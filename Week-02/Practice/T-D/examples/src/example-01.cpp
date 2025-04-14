#include <iostream>
// Temporary change to trigger rename
enum class A : unsigned int // Can't be floating numbers here
{
    Action,
    Adventure
};

int main()
{
    std::cout << static_cast<unsigned int>(A::Action) << std::endl;
}