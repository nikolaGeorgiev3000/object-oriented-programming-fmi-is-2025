#include <iostream>

struct A
{
	char word[5];
	int occupiedSpace;
};

int main()
{
    std::cout << sizeof(A) << std::endl; // 12

    return 0;
}