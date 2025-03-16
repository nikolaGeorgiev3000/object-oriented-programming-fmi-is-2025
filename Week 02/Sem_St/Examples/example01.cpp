#include <iostream>

struct ExampleSize01
{
    short b;
    int a;
    char c;
};

struct ExampleSize02
{
    int a;
    short b;
    char c;
};

struct Simple
{
    int x; // 4 bytes
    char data[3]; // 3 bytes
};

struct Complex
{
    Simple s; // 8
    char c; // 1
};

int main()
{
    // std::cout << sizeof(ExampleSize01) << std::endl; // 12
    // std::cout << sizeof(ExampleSize02) << std::endl; // 8
    std::cout << sizeof(Simple) << std::endl; // 4 + 3 * 1 + 1padding
    std::cout << sizeof(Complex) << std::endl; // 8 + 1 + 3padding

    return 0;
}