// Напишете функция filter, която приема масив arr от цели числа, за който е заделено 
// точно количество памет, и указател към предикат (функция, която приема цяло число 
// и връща булева стойност) pred. 
// Нека функцията задели памет за нов масив, който съдържа само тези елементи на arr, за които pred е истина.
#include <iostream>

size_t getCountOfElementsSatisfyingACondition(const int* arr, size_t size, bool(*pred)(int))
{
    if (!arr || !pred) return 0;

    size_t countToReturn = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (pred(arr[i])) 
            countToReturn++;
    }
    return countToReturn;
}

void filter(const int* arr, size_t size, int*& resultArr, size_t& resultSize, bool(*pred)(int))
{
    if (!arr || !pred) return;

    delete[] resultArr;
    resultSize = getCountOfElementsSatisfyingACondition(arr, size, pred);
    resultArr = new int[resultSize];

    int putIndex = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (pred(arr[i]))
        {
            resultArr[putIndex++] = arr[i];
        }
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

bool isOdd(int x)
{
	return x % 2 != 0;
}

int main()
{
    constexpr size_t SIZE = 6;
    int target = 3;
	{
		int arr[SIZE] = { 1,2,3,4,5,6 };
		int* result = nullptr;
		size_t resultSize = 0;

		filter(arr, SIZE, result, resultSize, [](int x) {
			return x % 2 != 0;
		});
		printArray(result, resultSize);
		
		delete[] result; // !!!
	}
    std::cout << std::endl;
	{
		int arr[SIZE] = { 1,2,3,4,5,6 };
		int* result = nullptr;
		size_t resultSize = 0;

		filter(arr, SIZE, result, resultSize, isOdd);
		printArray(result, resultSize);

		delete[] result; // !!!
	}
}