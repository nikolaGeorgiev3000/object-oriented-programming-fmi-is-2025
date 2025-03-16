#include <iostream>

struct Point
{
    double x, y;

    void readPoint()
    {
        std::cout << "Enter x: ";
        std::cin >> x;
        std::cout << "Enter y: ";
        std::cin >> y;
    }

    void printPoint() const
    {
        std::cout << "(" << this->x << ", " << this->y << ")\n";
    }

    double distanceTo(const Point &other) const
    {
        return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y)); // c = sqrt(a^2 + b^2)
    }
};

int main()
{
    // Point p1{1, 2};
    // Point p2{3, 5};

    Point p1, p2;

    std::cout << "Enter first point:\n";
    p1.readPoint();

    std::cout << "Enter second point:\n";
    p2.readPoint();

    std::cout << "\nFirst point: ";
    p1.printPoint();

    std::cout << "Second point: ";
    p2.printPoint();

    double distanceBtwn = p1.distanceTo(p2);

    std::cout << "Distance is: " << distanceBtwn << std::endl;

    return 0;
}