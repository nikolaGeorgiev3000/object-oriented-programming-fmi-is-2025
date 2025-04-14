#include <iostream>


void printArr(int *arr, int size) 
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << std::endl;
    }
}

enum class Course : long long int // We can set the `default type` for the enum class.
{
    First, Second, Third, Fourth
};

struct Student {
    char name[16];
    Course course;
    unsigned age; // The size of `unsigned` variable is 4 bytes.  
};

int main()
{
    // int a = 10;
    // int &b = a;
    // int *ptrC = &b;

    // std::cout << &a << std::endl;
    // std::cout << &b << std::endl;
    // std::cout << &ptrC << std::endl;

    // The memory is freed when we get out of the scope of the function
    // First is d, then c, then b, then a

    // int n;
    // std::cin >> n;

    // int *exampleArr = new int[n];

    // for (size_t i = 0; i < n; i++)
    // {
    //     *(exampleArr + i) = i * i;
    // }

    // printArr(exampleArr, n);

    // // Deallocate:
    // delete[] exampleArr;

    // std::cout << exampleArr[0]; // Wrong, since the array is already deallocated!

    std::cout << sizeof(Student);

    return 0;
}