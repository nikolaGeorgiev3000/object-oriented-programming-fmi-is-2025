// Създайте програма, която отпечатва на стандартния изход собствения си програмен код.
// Освен това изведете на стандартния изход следната статистика - броя на редовете в
// програмата, броя на редовете, в които има поне един символ, който е различен от нов ред,
// размера на файла в байтове.
#include <fstream>
#include <iostream>
#include <utility>

constexpr size_t MAX_BUFFER_LENGTH = 256;

int getByteSize(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        std::cerr << "Error opening file!\n";
        return -1;
    }
    int currPos = ifs.tellg(); // Save the current position

    ifs.seekg(0, std::ios::end); // Move the `get-pointer` to the end of the file

    int endPos = ifs.tellg(); // Save the end position

    ifs.clear();

    ifs.seekg(currPos, std::ios::beg); // Reset the position

    return endPos - currPos;
}

std::pair<int, int> getLinesCount(std::ifstream& ifs)
{
}

int main()
{
    const char fpath[] = "task01.cpp";

    std::ifstream ifs(fpath, std::ios::in);

    std::pair<int, int> lineCount = getLinesCount(ifs);
    int bytes = getByteSize(ifs);

    std::cout << "Lines count: " << lineCount.first << '\n'
              << "Non empty lines: " << lineCount.second << '\n'
              << "Size of the file in bytes: " << bytes << '\n';

    char buffer[256];

    std::cout << '\n';
    while (ifs.getline(buffer, 256))
    {
        std::cout << buffer << '\n';
    }

    return 0;
}