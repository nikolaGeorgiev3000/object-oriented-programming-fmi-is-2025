#include <iostream>

class A {};
class B {};
class C {};

class Entity
{
public:
    Entity() {
        std::cout << "Def called.\n";
    }

    ~Entity() {
        std::cout << "D-tor called.\n";
    }


private:
    A a;
    B b;
    C c;
};

int main()
{
    Entity e; // Конструктор по подразбиране.
    Entity e1(e); // Копиращ конструктор.
    e = e1; // Оператор за присвояване.


} // Деструктор на e и e1.