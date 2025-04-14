#include <iostream>

class Dummy
{
  public:
    Dummy() { std::cout << "Default ctor" << std::endl; }
    ~Dummy() { std::cout << "Dtor" << std::endl; }
};

void g()
{
    throw Dummy();
}

void f()
{
    Dummy d;
    g();
}

int main()
{
    Dummy d; // Default ctor
    try
    {
        f(); // Default ctor, Default ctor
    } // Dtor, Dtor
    catch (...)
    {
    }
    std::cout << "End" << std::endl;
} // Dtor