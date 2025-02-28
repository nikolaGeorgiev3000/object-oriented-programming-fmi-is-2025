#include <iostream>

enum class ReadingState
{
    Initial, Word, Whitespace
};

bool isLower(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isLetter(char c)
{
    return isLower(c) || isUpper(c);
}

size_t countWords(const char* str)
{
    if (!str) return 0;

    size_t countToReturn = 0;
    ReadingState state = ReadingState::Initial;

    while (*str)
    {
        if (isLetter(*str) && state != ReadingState::Word)
        {
            state = ReadingState::Word;
        }

        if (!isLetter(*str) && state == ReadingState::Word)
        {
            countToReturn++;
            state = ReadingState::Whitespace;
        }
        str++;
    }

    if (state == ReadingState::Word)
    {
        countToReturn++;
    }

    return countToReturn;
}

int main()
{
	std::cout << countWords("    ") << std::endl;
	std::cout << countWords("test") << std::endl;
	std::cout << countWords("Good morning, Vietnam!") << std::endl;
	std::cout << countWords("  Good  morning,     Vietnam!") << std::endl;
	std::cout << countWords("  Good  morning,     Vietnam!    ") << std::endl;
	std::cout << countWords("Good  morning, Vietnam!    ") << std::endl;
}