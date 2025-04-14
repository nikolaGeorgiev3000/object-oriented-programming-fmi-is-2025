#include <iostream>

class Entity 
{
private:
    static int x; // Не принадлежи на никой обект. Споделя се между обекти. Единствена.
public:
    static void f() {
        // do work
    }
};

int Entity::x = 0;

int main() 
{
    std::cout << Entity::x;
    Entity::f();
}