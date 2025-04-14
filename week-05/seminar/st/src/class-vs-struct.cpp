#include <iostream>

class Example1
{
    int x;
};

struct Example2
{
    int x;
};

int main()
{
    Example1 e1;
    // std::cout << e1.x << std::endl; // Error: inaccessible
    Example2 e2;
    std::cout << e2.x << std::endl; // Няма проблем, видимо по подразбиране.
}