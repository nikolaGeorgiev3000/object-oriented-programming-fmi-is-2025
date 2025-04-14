#include <iostream>

struct Point
{
    double x;
    double y;
};

void printPoint(const Point& p)
{
    std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl;
}

int main()
{
    Point ptArr[10];
    for (int i = 0; i < sizeof(ptArr) / sizeof(Point); i++)
    {
        ptArr[i].x = i;
        ptArr[i].y = i * i;
    }

    for (int i = 0; i < sizeof(ptArr) / sizeof(Point); i++)
    {
        printPoint(ptArr[i]);
    }

    std::cout << std::endl;

    // Dynamic point array
    Point* ptArrDyn = new Point[2];

    std::cin >> ptArrDyn[0].x;
    std::cin >> ptArrDyn[0].y;

    ptArrDyn[1].x = ptArrDyn[0].x * 2;
    ptArrDyn[1].y = ptArrDyn[0].y * 2;

    std::cout << "\nFirst point: ";
    printPoint(ptArrDyn[0]);
    std::cout << "Second point: ";
    printPoint(ptArrDyn[1]);

    // Clear the heap memory
    delete[] ptArrDyn;
}