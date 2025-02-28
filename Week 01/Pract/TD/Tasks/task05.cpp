// Напишете функция map, която приема масив arr от цели числа, за който е заделено 
// точно количество памет, и указател към функция func (приемаща и връщаща цяло число). 
// Нека функцията map промени всеки елемент на arr с резултата от func за съответния елемент.
#include <iostream>

void map(int* arr, size_t size, int(*mapper)(int))
{
    if (!arr || !mapper) return;

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = mapper(arr[i]);
    }
}

void printArray(const int* arr, size_t size)
{
    if (!arr) return;

    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int divBy2(int x)
{
    return x / 2;
}

int multBy2(int x)
{
    return x * 2;
}

int main()
{
    constexpr size_t SIZE = 5;
    {
        int arr[SIZE] = {1, 5, 2, -6, 2};

        map(arr, SIZE, [](int x) { return x / 2; });
        printArray(arr, SIZE);
        map(arr, SIZE, [](int x) { return x * 2; });
        printArray(arr, SIZE);
    }
    std::cout << std::endl;
    {
        int arr[SIZE] = {1, 5, 2, -6, 2};

        map(arr, SIZE, divBy2);
        printArray(arr, SIZE);
        map(arr, SIZE, multBy2);
        printArray(arr, SIZE);
    }

    return 0;
}
