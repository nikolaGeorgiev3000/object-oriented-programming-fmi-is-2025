#include <iostream>

struct Point
{
    int y;
    short x;
    char z;
};

int main()
{
    std::cout << "The size of the Point struct is: " << sizeof(Point) << " bytes." << std::endl;
    return 0;
}