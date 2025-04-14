// Напишете функция, която приема число K и два масива с произволен размер и връща
// нов масив с точна големина, съдържащ всички числа от двата масива, които се делят на K.

#include <iostream>

size_t countDivisiblesByK(const int *arr, size_t size, int k)
{
    if (!arr || k == 0)
        return 0;

    size_t countToReturn = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % k == 0)
            countToReturn++;
    }
    return countToReturn;
}

void getDivisiblesByK(int *&resultArr, size_t &resultArrSize,
                      const int *first, size_t sizeFirst,
                      const int *second, size_t sizeSecond,
                      int k)
{
    if (!first || !second || k == 0)
        return; // Validation

    delete[] resultArr; // Just to make sure, even if it's nullptr, it's safe.

    resultArrSize = countDivisiblesByK(first, sizeFirst, k) + countDivisiblesByK(second, sizeSecond, k);
    resultArr = new int[resultArrSize];

    int putIndex = 0;
    for (size_t i = 0; i < sizeFirst; i++)
    {
        if (first[i] % k == 0)
            resultArr[putIndex++] = first[i];
    }

    for (size_t i = 0; i < sizeSecond; i++)
    {
        if (second[i] % k == 0)
            resultArr[putIndex++] = second[i];
    }
}

// void readArr(int* arr, size_t size)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         std::cin >> arr[i];
//     }
    
//     return;
// }

void printArray(const int *arr, size_t size)
{
    if (!arr)
        return;

    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    constexpr size_t SIZE_FIRST = 5;
    constexpr size_t SIZE_SECOND = 10;
    int firstArr[SIZE_FIRST] = {5, 1, 2, 6, 1};
    int secondArr[SIZE_SECOND] = {2, 5, 1, -1, 2, 4, 6, 1, 10, 8};

    int k;
    std::cout << "Enter the divisor-number: ";
    std::cin >> k;

    size_t resultArrSize = 0;
    int* resultArr = nullptr;
    getDivisiblesByK(resultArr, resultArrSize, firstArr, SIZE_FIRST, secondArr, SIZE_SECOND, k);

    if (resultArr == nullptr) // We need `&` to a `*`, otherwise we end up here!
    {
        std::cout << "LoL";
        return 0;
    }

    printArray(resultArr, resultArrSize);

    // Free the heap
    delete[] resultArr;
}