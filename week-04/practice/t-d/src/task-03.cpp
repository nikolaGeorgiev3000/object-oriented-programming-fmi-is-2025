/*
    Да се напише програма, която чете двоичен файл, съдържащ неопределен брой двойки стойности (x, y),
    представляващи координати в декартова координатна система. След прочитането на данните да се изчисли
    центърът на тежестта на всички точки. След това да се намерят трите най-близки точки до центъра на тежестта
    и техните координати да се запишат в нов двоичен файл.
*/

#include <cmath>
#include <fstream>
#include <iostream>

constexpr size_t MAX_POINTS = 1024;

struct Point
{
    float x, y;
};

float distanceTo(const Point& a, const Point& b)
{
    float dy = a.y - b.y;
    float dx = a.x - b.x;

    return std::sqrt(dx * dx + dy * dy);
}

bool readPointsFromBinaryFile(const char* filename, Point* pts, size_t& count)
{
    if (!filename)
        return false;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
        return false;

    count = 0; // Just in case

    while (inFile.read(reinterpret_cast<char*>(&pts[count]), sizeof(Point)))
    {
        ++count;
        if (count > MAX_POINTS)
            break;
    }

    inFile.close();

    return true;
}

Point calculateCenterOfMass(const Point* pts, size_t count)
{
    Point center = {0.0f, 0.0f};

    for (size_t i = 0; i < count; ++i)
    {
        center.x += pts[i].x;
        center.y += pts[i].y;
    }
    center.x /= count;
    center.y /= count;

    return center;
}

void findThreeClosestPoints(const Point* points, size_t count, const Point& center, size_t* outIndices)
{
    float distances[3];
    for (size_t i = 0; i < 3; ++i)
    {
        distances[i] = distanceTo(points[i], center);
        outIndices[i] = i;
    }

    for (size_t i = 3; i < count; ++i)
    {
        float d = distanceTo(points[i], center);

        // Намери най-отдалечения индекс от текущите трима
        size_t maxIdx = 0;
        for (size_t j = 1; j < 3; ++j)
            if (distances[j] > distances[maxIdx])
                maxIdx = j;

        if (d < distances[maxIdx])
        {
            distances[maxIdx] = d;
            outIndices[maxIdx] = i;
        }
    }
}

bool writePointsToBinaryFile(const char* filename, const Point* points, const size_t* indices, size_t count)
{
    if (!filename || !points || !indices)
        return false;

    std::ofstream out(filename, std::ios::binary);
    if (!out.is_open())
        return false;

    for (size_t i = 0; i < count; ++i)
        out.write(reinterpret_cast<const char*>(&points[indices[i]]), sizeof(Point));

    out.close();
    return true;
}

bool find3ClosestToCenter(const char* inputFile, const char* outputFile)
{
    Point points[MAX_POINTS];
    size_t pointCount = 0;

    if (!readPointsFromBinaryFile(inputFile, points, pointCount))
        return false;
    if (pointCount < 3)
        return false;

    Point center = calculateCenterOfMass(points, pointCount);

    size_t closestIndices[3];
    findThreeClosestPoints(points, pointCount, center, closestIndices);

    return writePointsToBinaryFile(outputFile, points, closestIndices, 3);
}