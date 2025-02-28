#include <iostream>

int f(int a)
{
    a++;
    return a;
}
int g(int& a)
{
    a++;
    return a;
}
int h(int* a)
{
    (a++);
    a++;
    return *a;
}
int k(int* a)
{
    (*a)++;
    return *a;
}

int main()
{
    int a = 10, b = 10, c = 10, d = 10;
    // f(a);
    // std::cout << a << std::endl; 
    // g(b);
    // std::cout << b << std::endl;
    int something = h(&c);
    std::cout << something << std::endl;
    std::cout << c << std::endl;
    // k(&d);
    // std::cout << d << std::endl;
}