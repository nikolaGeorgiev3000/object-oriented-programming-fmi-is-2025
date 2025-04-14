#include <iostream>
#include <math.h>

struct Point
{
    int x, y;
};

double getDistBtwPoints(const Point& a, const Point& b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

struct Line
{
    Point a, b;
};

double getSlope(const Line& l)
{
    double dx = l.b.x - l.a.x;
    if (dx == 0)
        return INFINITY; // Handle vertical lines
    double dy = l.b.y - l.a.y;

    return dy / dx;
}

bool arePar(const Line& l1, const Line& l2)
{
    return abs(getSlope(l1) - getSlope(l2)) <= 0.0001;
}

int main()
{
    Line l1{1, 2, 3, 4};
    Line l2{0, 1, 2, 3};

    std::cout << std::boolalpha << arePar(l1, l2); // True

    return 0;
}
