#include <cmath>
#include <iostream>

#define MAX_N 100 // Максимален брой триъгълници

struct Point
{
    double x, y;
};

struct Triangle
{
    Point A, B, C;

    double area() const
    {
        double a = distance(A, B);
        double b = distance(B, C);
        double c = distance(C, A);
        double s = (a + b + c) / 2; // Полупериметър
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

  private:
    static double distance(const Point& p1, const Point& p2)
    {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

// Функция за ръчно сортиране (Bubble Sort)
void sortTriangles(Triangle triangles[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (triangles[j].area() > triangles[j + 1].area())
            {
                // Размяна на елементи
                Triangle temp = triangles[j];
                triangles[j] = triangles[j + 1];
                triangles[j + 1] = temp;
            }
        }
    }
}

void printTriangle(const Triangle& t)
{
    std::cout << "Triangle: (" << t.A.x << ", " << t.A.y << "), "
              << "(" << t.B.x << ", " << t.B.y << "), "
              << "(" << t.C.x << ", " << t.C.y << ") | Area: "
              << t.area() << std::endl;
}

int main()
{
    int N;
    std::cout << "Enter the number of triangles: ";
    std::cin >> N;

    if (N > MAX_N)
    {
        std::cerr << "Error: Exceeded maximum allowed triangles (" << MAX_N << ")" << std::endl;
        return 1;
    }

    Triangle triangles[MAX_N];

    for (int i = 0; i < N; i++)
    {
        std::cout << "Enter coordinates for triangle " << i + 1 << " (x1 y1 x2 y2 x3 y3): ";
        std::cin >> triangles[i].A.x >> triangles[i].A.y >> triangles[i].B.x >> triangles[i].B.y >> triangles[i].C.x >> triangles[i].C.y;
    }

    // Сортиране на триъгълниците по лице (ръчно реализирано)
    sortTriangles(triangles, N);

    // Извеждане на резултата
    std::cout << "\nSorted Triangles by Area:\n";
    for (int i = 0; i < N; i++)
    {
        printTriangle(triangles[i]);
    }

    return 0;
}