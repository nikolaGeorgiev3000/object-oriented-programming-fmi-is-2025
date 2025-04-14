/*
3. Напишете функция, която приема имена на два текстов файла и копира съдържанието на първия файл във втория.
*/
#include <fstream>
#include <iostream>

bool copyFile(const char* sourceName, const char* destName)
{
    if (!sourceName || !destName)
        return false;

    std::ifstream inFile(sourceName);

    if (!inFile.is_open())
    {
        std::cerr << "Error opening the source file.\n";
        return false;
    }

    std::ofstream outFile(destName);

    if (!outFile.is_open())
    {
        std::cerr << "Error opening the destination file.\n";
        inFile.close(); // Close the input-stream, because we successfully opened it.
        return false;
    }

    char ch;
    while (inFile.get(ch))
    {
        outFile.put(ch); // outFile << ch; also works, but might create some complications with other primitive types
    }

    // Close the streams
    inFile.close();
    outFile.close();

    return true;
}

int main()
{
    bool isSuccessful = copyFile("task01_testFile.txt", "task03_destFile.txt");

    if (isSuccessful)
    {
        std::cout << "The operation is successful!";
        return 0;
    }
}