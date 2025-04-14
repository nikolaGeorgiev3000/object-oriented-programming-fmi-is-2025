/*
2. Напишете функция, която приема име на текстов файл и принтира броя на редовете в него.
*/
#include <fstream>
#include <iostream>

int countLinesInFile(const char* filename)
{
    if (!filename)
        return -1;

    std::ifstream inFile(filename);

    if (!inFile.is_open())
    {
        std::cerr << "Грешка при отваряне на файла: " << filename << std::endl;
        return -1;
    }

    size_t linesCount = 0;
    char ch;
    bool isEmpty = true;

    while (inFile.get(ch))
    {
        isEmpty = false;
        if (ch == '\n')
            ++linesCount;
    }

    // Close the stream when finished operations with it
    inFile.close();

    if (!isEmpty && ch == '\n')
    { // If the last row is empty
        ++linesCount;
    }

    return linesCount;
}

int main()
{
    int lines = countLinesInFile("task01_testFile.txt");

    if (lines != -1)
    {
        std::cout << "Редове във файла: " << lines << std::endl;
    }

    return 0;
}