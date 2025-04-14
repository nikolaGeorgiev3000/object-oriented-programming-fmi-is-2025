#include "functions.h"

size_t getOccurences(std::ifstream& ifs, char ch)
{
    size_t count = 0;
    size_t currentIndex = ifs.tellg(); // Save the current position
    char currentCh;

    ifs.seekg(0, std::ios::beg); // Move the `get` pointer to the beginning of the file

    while (ifs.get(currentCh)) // Reads the current character & checks for EOF
    {
        if (currentCh == ch)
            ++count;
    }

    ifs.clear();             // Clear the EOF flag in case of EOF hit
    ifs.seekg(currentIndex); // Restore position

    return count;
}