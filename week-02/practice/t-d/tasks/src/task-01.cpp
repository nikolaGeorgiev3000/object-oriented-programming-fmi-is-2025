#include <iostream>

enum class Status
{
    OK,
    Error
};

struct ParseResult
{
    int number;
    Status status;
};

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

ParseResult parse(const char* input)
{
    ParseResult toReturn;
    if (!input)
    {
        toReturn.status = Status::Error;
        toReturn.number = 0; // ?
        return toReturn;
    }

    toReturn.status = Status::OK;
    toReturn.number = 0;

    for (size_t i = 0; i != '\0'; i++)
    {
        if (!isDigit(input[i]))
        {
            toReturn.status = Status::Error;
            return toReturn;
        }
        toReturn.number = 10 * toReturn.number + (input[i] - '\0');
    }
    return toReturn;
}

int main()
{
    constexpr size_t MAX_SIZE = 100;

    char input[MAX_SIZE];

    // Enter your input:
    std::cout << "Enter a number: ";
    std::cin >> input;

    ParseResult result = parse(input);

    if (result.status == Status::Error)
    {
        std::cout << "{number: " << result.number << ", statusCode: " << static_cast<char>(result.status) << "}" << std::endl;
    }
    else
    {
        std::cout << "{number: _, statusCode: " << static_cast<char>(result.status) << "}" << std::endl;
    }
    return 0;
}