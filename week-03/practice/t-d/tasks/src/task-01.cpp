/*
1. Напишете функция, която приема име на текстов файл и принтира на стандартния изход съдържанието му.
*/
#include <iostream>
#include <fstream>

void printFileContent(const char* fileName) {
    if (!fileName) return;

    std::ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cerr << "Грешка при отваряне на файла: " << fileName << std::endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        std::cout << ch;
    }

    inFile.close();
}

int main() {
    printFileContent("task01_testFile.txt");
}