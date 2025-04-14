/*
    Напревете следните функционалности:
        записване на масив от цели числа в двоичен файл
        прочитане на двоичен файл с цели числа и да се съхрани в подходящ масив
        извличане n-то число от двоичен файл, като двоичния файл не се зарежда в паметта (гарантирано е, че n < броя на числата)
    Упътване: целите числа са от тип int
*/
#include <fstream>
#include <iostream>

bool writeIntArrayToBinaryFile(const char* outputFilename, const int* arr, size_t arrSize)
{
    if (!outputFilename || !arr)
        return false;

    std::ofstream outFile(outputFilename, std::ios::binary);

    if (!outFile.is_open())
        return false;

    outFile.write(reinterpret_cast<const char*>(arr), arrSize * sizeof(int));

    outFile.close();

    return true;
}

bool readIntArrayFromBinaryFile(const char* filename, int* arr, size_t maxSize, size_t& outSize)
{
    if (!filename || !arr)
        return false;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
        return false;

    // Find file size
    std::streampos currPos = inFile.tellg();
    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();
    inFile.seekg(static_cast<size_t>(currPos), std::ios::beg);

    size_t totalNumCount = static_cast<size_t>(fileSize) / sizeof(int);

    if (totalNumCount > maxSize)
        return false;

    inFile.read(reinterpret_cast<char*>(arr), totalNumCount * sizeof(int));
    outSize = totalNumCount;

    inFile.close();

    return true;
}

bool readNthIntFromBinaryFile(const char* filename, size_t n, int& result)
{
    if (!filename)
        return false;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open())
        return false;

    // std::streampos currPos = inFile.tellg();
    inFile.seekg((n - 1) * sizeof(int), std::ios::beg);

    inFile.read(reinterpret_cast<char*>(&result), sizeof(int));

    if (!inFile)
        return false;

    // inFile.seekg(static_cast<size_t>(currPos), std::ios::beg);

    inFile.close();

    return true;
}

int main()
{
    const char* filename = "ints.bin";
    int arr[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    if (writeIntArrayToBinaryFile(filename, arr, size))
        std::cout << "Успешен запис.\n";

    constexpr size_t MAX_ARR_SIZE = 100;
    int buffer[MAX_ARR_SIZE];
    size_t readSize;

    if (readIntArrayFromBinaryFile(filename, buffer, MAX_ARR_SIZE, readSize))
    {
        std::cout << "Прочетени числа: ";
        for (size_t i = 0; i < readSize; ++i)
            std::cout << buffer[i] << " ";
        std::cout << std::endl;
    }

    const size_t posNumber = 4;
    int resultValue;

    if (readNthIntFromBinaryFile(filename, posNumber, resultValue))
    {
        std::cout << "4-то число във файла е: " << resultValue << std::endl;
    }

    return 0;
}