#include "pch.h"
#include "Triangle.h"
#include <iostream>

void readTriangle(Triangle &t)
{
    readPoint(t.A);
    readPoint(t.B);
    readPoint(t.C);
}

void readTriangles(Triangle *triangles, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        readTriangle(triangles[i]);
    }
}

void printTriangle(const Triangle &t)
{
    printPoint(t.A);
    std::cout << ", ";
    printPoint(t.B);
    std::cout << ", ";
    printPoint(t.C);
}

void printTriangles(const Triangle *triangles, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printTriangle(triangles[i]);
        std::cout << std::endl; // Indentation
    }
}