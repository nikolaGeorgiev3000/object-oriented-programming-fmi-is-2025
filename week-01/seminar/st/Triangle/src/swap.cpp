#include "swap.h"
#include "pch.h"

void swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swap(Triangle& t1, Triangle& t2)
{
    Triangle temp = t1;
    t1 = t2;
    t2 = temp;
}