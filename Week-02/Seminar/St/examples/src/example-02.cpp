#include <fstream>
#include <iostream>

int main()
{
    // Write to file
    std::ofstream outFile("example02.txt");

    if (!outFile.is_open())
        return -1;

    outFile << "Hello, dear file";
    outFile.put('!');

    outFile.close();

    // Read from file
    std::ifstream inFile("example02.txt");

    if (!inFile.is_open())
        return -1;

    constexpr size_t BUFF_LINE_SIZE = 64;
    char buffLine[BUFF_LINE_SIZE];

    inFile.getline(buffLine, BUFF_LINE_SIZE, '\n');

    std::cout << "The first line of our file is: " << buffLine;

    char ch = inFile.get();

    std::cout << "\nThe next symbol is: " << ch; // If there aren't more symbols -> bad...

    inFile.close(); // Never forget to close the stream
    return 0;
}