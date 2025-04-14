#include <iostream>
#include <stdexcept>

double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("Division by zero");
    return a / b;
}

int main()
{
    try
    {
        std::cout << divide(4, 0);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what();
    }
}