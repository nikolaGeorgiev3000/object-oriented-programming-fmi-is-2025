#include <iostream>

// Optimized Bubble Sort
void sortBubble(int* arr, unsigned arrSize) 
{
    int temp;
    for (size_t i = 0; i < arrSize - 1; ++i)
    {
        bool flag = false;
        for (size_t j = 0; j < arrSize - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = true;
            }
        }
        if (!flag) break; // If there wasn't any swap in an iteration, the array is sorted
    }
}

void printArr(int* arr, unsigned arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Testing Bubble Sort
    int arr[9] = {1, -5, 23, 5, 12, -50, 21, 45, 322};

    std::cout << "Before sorting: ";
    printArr(arr, 9);

    sortBubble(arr, 9);

    std::cout << "After sorting: ";
    printArr(arr, 9);

    return 0;    
}
