/* 
5. Напишете функция, която приема имената на два текстови файла, в които са записани цели числа в сортиран вид. 
Числата са разделени с интервал. Запишете в нов файл числата от двата дайла в сортиран вид. 
Числата отново да са разделени с интервал.
НЕ Е позволено да използвате масив, за да пазите временно числата.
*/
#include <iostream>
#include <fstream>

bool mergeSortedFiles(const char* inputFilename1, const char* inputFilename2, const char* outputFilename) {
    if (!inputFilename1 || !inputFilename2 || !outputFilename) return false;

    std::ifstream inFile1(inputFilename1);
    std::ifstream inFile2(inputFilename2);
    std::ofstream outFile(outputFilename, std::ios::app); // Open the stream with append mode

    if (!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open()) {
        std::cerr << "Грешка при отваряне на файлове!" << std::endl;
        return false;
    }

    int num1, num2;
    bool has1 = bool(inFile1 >> num1);
    bool has2 = bool(inFile2 >> num2);

    while (has1 && has2) {
        if (num1 <= num2) {
            outFile << num1 << ' ';
            has1 = bool(inFile1 >> num1);
        } else {
            outFile << num2 << ' ';
            has2 = bool(inFile2 >> num2);
        }
    }

    while (has1) {
        outFile << num1 << ' ';
        has1 = bool(inFile1 >> num1);
    }

    while (has2) {
        outFile << num2 << ' ';
        has2 = bool(inFile2 >> num2);
    }

    // Close all streams
    inFile1.close(); inFile2.close(); outFile.close();

    return true; // Successful operation!
}

int main() {
    if (!mergeSortedFiles("task05_file01.txt", "task05_file02.txt", "task05_outputFile.txt")) {
        std::cerr << "Error in merging sorted files\n";
        return -1;
    }

    std::cout << "Operation successful!\n";

    return 0;
}