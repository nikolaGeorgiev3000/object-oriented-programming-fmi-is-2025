#include <iostream>

enum class Color
{
    Red = 1, Orange = 1, Blue
};
enum class Fruit
{
    Apple, Orange, Banana
};

int main()
{
    Color c = Color::Red;
    Fruit f = Fruit::Apple;

    std::cout << (static_cast<int>(c) == static_cast<int>(f) ? "yes" : "no") << std::endl;

    Color anotherColor = static_cast<Color>(1);
    int colorVal = static_cast<int>(Color::Orange);
}