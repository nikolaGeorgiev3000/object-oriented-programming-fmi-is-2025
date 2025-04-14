// Create a structure about the figure `Triangle`
#include <iostream>
#include <cmath>

enum class TriangleTypeBySides
{
    Equilateral,
    Isosceles,
    Scalene
};

enum class TriangleTypeByAngles
{
    RightAngled,
    AcuteAngled,
    ObtuseAngled
};

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

struct Triangle
{
    Point a, b, c;
    double side1, side2, side3;

    void readTriangle()
    {
        std::cout << "Enter the coordinates of point A:\n";
        a.readPoint();
        std::cout << "Enter the coordinates of point B:\n";
        b.readPoint();
        std::cout << "Enter the coordinates of point C:\n";
        c.readPoint();

        side1 = a.distanceTo(b);
        side2 = b.distanceTo(c);
        side3 = c.distanceTo(a);

        std::cout << std::endl;
    }

    void printTriangleVertices() const
    {
        std::cout << "A(" << a.x << ", " << a.y << ")\n";
        std::cout << "B(" << b.x << ", " << b.y << ")\n";
        std::cout << "C(" << c.x << ", " << c.y << ")\n";
    }

    // Calculate the perimeter of the triangle
    double getPerimeter() const
    {
        return this->side1 + this->side2 + this->side3;
    }

    // Calculate the area of the triangle using Heron's formula
    double getArea() const
    {
        double halfPerimeter = this->getPerimeter() / 2;
        return std::sqrt(halfPerimeter * (halfPerimeter - side1) * (halfPerimeter - side2) * (halfPerimeter - side3));
    }

    // Get triangle type based on the sides
    TriangleTypeBySides getTriangleTypeBySides() const
    {
        if (std::fabs(side1 - side2) < 1e-9 && (side2 - side3) < 1e-9)
        {
            return TriangleTypeBySides::Equilateral;
        }
        else if (std::fabs(side1 - side2) < 1e-9 || (side2 - side3) < 1e-9 || (side3 - side1) < 1e-9)
        {
            return TriangleTypeBySides::Isosceles;
        }
        else
        {
            return TriangleTypeBySides::Scalene;
        }
    }

    // Get triangle type based on the angles
    TriangleTypeByAngles getTriangleTypeByAngles() const
    {
        double a2 = side1 * side1;
        double b2 = side2 * side2;
        double c2 = side3 * side3;

        if (std::fabs(a2 + b2 - c2) < 1e-9 || (a2 + c2 - b2) < 1e-9 || (b2 + c2 - a2) < 1e-9)
        {
            return TriangleTypeByAngles::RightAngled;
        }
        else if ((a2 + b2) > c2 && (b2 + c2) > a2 && (a2 + c2) > b2)
        {
            return TriangleTypeByAngles::AcuteAngled;
        }
        else
        {
            return TriangleTypeByAngles::ObtuseAngled;
        }
    }
};

// Helper functions for the `Triangle` structure

// Convert TriangleTypeBySides to string
const char *triangleTypeBySidesToString(TriangleTypeBySides type)
{
    switch (type)
    {
    case TriangleTypeBySides::Equilateral:
        return "Equilateral";
    case TriangleTypeBySides::Isosceles:
        return "Isosceles";
    case TriangleTypeBySides::Scalene:
        return "Scalene";
    default:
        return "Unknown";
    }
}

// Convert TriangleTypeByAngles to string
const char *triangleTypeByAnglesToString(TriangleTypeByAngles type)
{
    switch (type)
    {
    case TriangleTypeByAngles::RightAngled:
        return "Right-Angled";
    case TriangleTypeByAngles::AcuteAngled:
        return "Acute-Angled";
    case TriangleTypeByAngles::ObtuseAngled:
        return "Obtuse-Angled";
    default:
        return "Unknown";
    }
}

int main()
{
    Triangle t;
    t.readTriangle();

    std::cout << "Triangle info:\n";
    t.printTriangleVertices();

    std::cout << "\nTriangle perimeter: " << t.getPerimeter() << std::endl;
    std::cout << "Triangle area: " << t.getArea() << std::endl;
    std::cout << "Triangle type by sides: " << triangleTypeBySidesToString(t.getTriangleTypeBySides()) << std::endl;
    std::cout << "Triangle type by angles: " << triangleTypeByAnglesToString(t.getTriangleTypeByAngles()) << std::endl;
}