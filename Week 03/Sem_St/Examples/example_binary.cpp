#include <iostream>
#include <fstream>
#include <cstring>

constexpr size_t ARR_SIZE = 10;

void writeBinaryFile(const char* filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    int x = 10;
    const char* text = "Into the binary file.";
    int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    size_t textLength = strlen(text);

    // Write data to binary file
    outFile.write(reinterpret_cast<const char*>(&textLength), sizeof(size_t)); // Store text length
    outFile.write(text, textLength);
    outFile.write(reinterpret_cast<const char*>(&x), sizeof(int));
    outFile.write(reinterpret_cast<const char*>(arr), ARR_SIZE * sizeof(int));

    std::cout << "Data written successfully.\n";
}

void readBinaryFile(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    size_t textLength;
    inFile.read(reinterpret_cast<char*>(&textLength), sizeof(size_t)); // Read text length

    char* line = new char[textLength + 1]; // Allocate memory dynamically
    inFile.read(line, textLength);
    line[textLength] = '\0'; // Null-terminate the string

    int x;
    int arr[ARR_SIZE];

    inFile.read(reinterpret_cast<char*>(&x), sizeof(int));
    inFile.read(reinterpret_cast<char*>(arr), ARR_SIZE * sizeof(int));

    std::cout << line << "\n" << x << "\n";
    for (size_t i = 0; i < ARR_SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] line; // Clean up dynamically allocated memory
}

int main() {
    const char* filename = "test.dat";

    writeBinaryFile(filename);
    readBinaryFile(filename);

    return 0;
}