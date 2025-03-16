#include <iostream>
#include <fstream>

#define BUFF_SIZE 64

void selfPrint(const char* fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open()) 
        std::cerr << "Unable to open file" << std::endl;

    char buff[BUFF_SIZE];
    while (file.getline(buff, BUFF_SIZE)) {
        std::cout << buff << std::endl;
    }
    file.close();
}

int main() {
    selfPrint("selfPrintingProgram.cpp");

    return 0;
}