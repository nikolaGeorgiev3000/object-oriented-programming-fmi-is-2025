#include <iostream>

#define SQUARE(x) ((x) * (x))
#define true false // Horrendous
#define SOMETHING_RANDOM "Random String"
#define SOMETHING_RANDOM_WITHOUT_VALUE

#ifndef SOMETHING_RANDOM_WITHOUT_VALUE
#define MESSAGE "Not defined"
#else
#define MESSAGE "Defined."
#endif

int main()
{
    int fiveSquared = SQUARE(5);

    if (!true)
    {
        std::cout << "Syke...";
    }

    std::cout << MESSAGE << std::endl;
    std::cout << fiveSquared << std::endl;
    std::cout << SOMETHING_RANDOM << std::endl;
    // std::cout << SOMETHING_RANDOM_WITHOUT_VALUE; // Error
}