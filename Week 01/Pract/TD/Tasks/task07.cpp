/*
    Напишете функция partition, която приема масив arr от n на брой цели числа, 
    за който е заделено точно количество памет, и указател към предикат 
    (функция, която приема цяло число и връща булева стойност) pred. Нека функцията 
    размести елементите на масива, така, че той да може да бъде разделен на 
    2 продължителни части - такава, която съдържа само тези елементи на arr, 
    за които pred е истина, и такава, която съдържа само тези елементи на arr, за които pred е лъжа.
*/

/*
    Follow-up: 
    Подобна реализация на функцията partition, с малко модификации и връщаща индекса, 
    при който е "границата", спрямо предиката, се използва в рекурсивния алгоритъм за сортиране quicksort.
*/

/* 
    Input: [1, 2, 3, 4, 5] And [](int a) { return a % 2 == 0; }
    Output: [2, 4, 3, 1, 5]
*/

#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b; 
    b = temp;
}

void partition(int* arr, size_t size, bool(*pred)(int))
{
    if (!arr || !pred) return;

    int partitionIndex = 0;

    for (size_t i = 0; i < size; i++)
    {
        if(pred(arr[i]))
        {
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
}

void printArr(const int* arr, size_t size)
{
    if (!arr) return;

    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    constexpr size_t SIZE = 5; // Compile-time
    {
        int arr[SIZE] = {1, 2, 3, 4, 5};
        partition(arr, SIZE, [](int x) { return x % 2 == 0; });
        printArr(arr, SIZE);
    }
    std::cout << std::endl;
    {
        int arr[SIZE] = {1, 2, 3, 4, 5};
        partition(arr, SIZE, isEven);
        printArr(arr, SIZE);
    }
    std::cout << std::endl;
    {
        constexpr size_t SIZE_LOCAL = 11;
        int arr[SIZE_LOCAL] = {1, 2, 3, 4, 5, -5, 2, 51, -4, -13, 41};
        partition(arr, SIZE_LOCAL, [](int x) { return abs(x) > static_cast<int>(SIZE_LOCAL); });
        printArr(arr, SIZE_LOCAL);
    }

    return 0;
}
