#pragma once
#include "Point.h"
#include <cstddef>

struct Triangle
{
    Point A, B, C;
};

void readTriangle(Triangle &);
void readTriangles(Triangle *, size_t);
void printTriangle(const Triangle &);
void printTriangles(const Triangle *, size_t);