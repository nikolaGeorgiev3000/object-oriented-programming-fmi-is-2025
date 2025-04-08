#include <iostream>

struct A 
{
	char word[5];
	int occupiedSpace;
};

struct B 
{
	char word[5];
	double occupiedSpace;
};

struct C 
{
	int length;
	char word[5];
};

struct D 
{
    double f;
    char k;
};

struct E 
{
    D obj;
    char c;
};

struct F 
{
    double f;
    char k;
    char c;
};

int main()
{
    std::cout << sizeof(A) << std::endl; // 12
    std::cout << sizeof(B) << std::endl; // 16
    std::cout << sizeof(C) << std::endl; // 12
    std::cout << sizeof(D) << std::endl; // 16
    std::cout << sizeof(E) << std::endl; // 24
    std::cout << sizeof(F) << std::endl; // 16

    return 0;
}