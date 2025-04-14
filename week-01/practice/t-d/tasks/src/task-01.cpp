// 1. Напишете функция, която приема символен низ и връща ново заделен символен низ,
// съдържащ само цифрите от подадения низ.
// Temporary change to trigger rename
#include <iostream>

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

size_t countDigits(const char* str)
{
    if (!str)
        return 0;

    size_t count = 0;

    while (*str)
    {
        if (isDigit(*str))
            ++count;
        str++;
    }

    return count;
}

char* filterDigits(const char* str)
{
    if (!str)
        return nullptr;

    size_t digitsCount = countDigits(str);
    char* toReturn = new char[digitsCount + 1];

    int putIndex = 0;
    while (*str)
    {
        if (isDigit(*str))
        {
            toReturn[putIndex++] = *str;
        }
        str++;
    }

    toReturn[putIndex] = '\0';

    return toReturn;
}

int main()
{
    char* filtered = filterDigits(")Lso!c6d%9ucpB*CED5su2DH%&7t4)*");
    std::cout << filtered << std::endl;

    // Free the heap memory
    delete[] filtered;

    return 0;
}