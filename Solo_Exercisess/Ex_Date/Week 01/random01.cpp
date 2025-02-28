#include <iostream>

int main()
{
    int arr[] = {1, 2, 3};
    *(arr + 2) = 5; // arr[2] = 5;
    int *q = arr + 2;
    int **p = &q;
    std::cout << &arr[2] << std::endl;
    std::cout << &(**p) << std::endl; // == &arr[2]
    std::cout << &q << std::endl;
    std::cout << &(*p) << std::endl; // == &q

    return 0;
}