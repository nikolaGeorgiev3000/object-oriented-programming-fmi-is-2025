/*
    1) Напишете програма, която приема файл и показва каква е големината му.
*/


#include <iostream>
#include <fstream>

int getFileSizeBasic(const char* filename) {
    if (!filename) return -1;

    std::ifstream inFile(filename);

    if (!inFile.is_open()) return -1;

    unsigned currPos = inFile.tellg();
    inFile.seekg(0, std::ios::end);
    unsigned fileSize = inFile.tellg();
    inFile.seekg(currPos, std::ios::beg);

    return fileSize;
}

int getFileSizeUniversal(const char* filename) {
    if (!filename) return -1;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) return -1;

    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();

    return static_cast<int>(fileSize);
}

int main() {
    std::cout << getFileSizeBasic("task01.cpp") << " bytes" << std::endl;
    std::cout << getFileSizeUniversal("task01.cpp") << " bytes" << std::endl;
}