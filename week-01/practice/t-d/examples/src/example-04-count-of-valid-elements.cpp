#include <iostream>

size_t getCountOfElementsSatisfyingACondition(const int *arr, size_t size, bool (*pred)(int))
{
    if (!arr || !pred) // Invalid pointers
    {
        return 0;
    }

    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (pred(arr[i]))
        {
            ++count;
        }
    }
    return count;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

bool isOdd(int x)
{
    return x % 2 != 0;
}

int main()
{
    constexpr size_t SIZE = 10;
    int arr[SIZE] = {-1, 5, -3, 5, -2, 2, 6, 3, 2, 9};

    // std::cout << getCountOfElementsSatisfyingACondition(arr, SIZE, isEven) << std::endl;
    // std::cout << getCountOfElementsSatisfyingACondition(arr, SIZE, isOdd) << std::endl;

    // std::cout << getCountOfElementsSatisfyingACondition(arr, SIZE, [](int a)
    //                                                     { return abs(a) % 3 == 2; })
    //           << std::endl;

    // More lambda func examples
    int threshold = 10;
    auto checkGreater = [threshold](int x) { return x > threshold; };
    std::cout << std::boolalpha << checkGreater(11);              
    std::cout << std::boolalpha << checkGreater(9);
    
    // More examples
    int sum = 0;
    auto addToSum = [&sum](int x) { sum += x; };
    addToSum(10);
    std::cout << "\n" << sum << std::endl;

    return 0;
}