#include <fstream>
#include <iostream>

unsigned getFileSize(std::ofstream& out)
{
    if (!out.is_open())
    {
        std::cerr << "Error with the file.\n";
        return 0;
    }

    unsigned currentPosition = out.tellp();
    out.seekp(0, std::ios::end);
    unsigned fileSize = out.tellp();
    out.seekp(currentPosition, std::ios::beg);
    return fileSize;
}

int main()
{
    std::ofstream outFile("file_size.cpp", std::ios::binary | std::ios::app);

    std::cout << "The size of the current file is: "
              << getFileSize(outFile) << " Bytes\n";

    return 0;
}