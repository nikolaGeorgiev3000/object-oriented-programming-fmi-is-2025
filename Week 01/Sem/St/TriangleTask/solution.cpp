#include "pch.h"
#include "swap.h"

#include <iostream>

double getDistance(const Point &, const Point &);
double getArea(const Triangle &);
void calculateAreas(const Triangle *, int, double*);
void selectionSort(Triangle *, int, double *);

int main()
{
    int n;
    std::cin >> n;

    Triangle *triangles = new Triangle[n];
    readTriangles(triangles, n);

    double *areas = new double[n];
    calculateAreas(triangles, n, areas);

    selectionSort(triangles, n, areas);

    printTriangles(triangles, n);

    // Free memory
    delete[] triangles;
    delete[] areas;

    return 0;
}

double getDistance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

double getArea(const Triangle &t)
{
    double side01 = getDistance(t.A, t.B);
    double side02 = getDistance(t.B, t.C);
    double side03 = getDistance(t.C, t.A);

    double halfPer = (side01 + side02 + side03) / 2;

    return sqrt(halfPer * (halfPer - side01) * (halfPer - side02) * (halfPer - side03));
}

void calculateAreas(const Triangle *triangles, int n, double *areas)
{
    for (int i = 0; i < n; i++)
    {
        areas[i] = getArea(triangles[i]);
    }
}

void selectionSort(Triangle *triangles, int n, double *areas)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (areas[j] < areas[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(triangles[i], triangles[minIndex]); // swap triangles
            swap(areas[i], areas[minIndex]);         // swap areas(numbers)
        }
    }
}