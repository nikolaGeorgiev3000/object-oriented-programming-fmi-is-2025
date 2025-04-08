/* 
4. Напишете програма, която чете три цели числа от стандартния вход. 
Напишете функция, която приема трите числа и име на файл, в който ще запишете сумата и произведението им.
*/
#include <iostream>
#include <fstream>

void writeSumAndProductToFile(int a, int b, int c, const char* filename) {
    if (!filename) return;

    std::ofstream outFile(filename); // Text work

    if (!outFile.is_open()) {
        std::cerr << "Error opening file with name: " << filename;
        return;    
    }

    int sum = a + b + c;
    int product = a * b * c;

    // Write the sum & product
    outFile << "Сума: " << sum << std::endl;
    outFile << "Произведение: " << product << std::endl;

    outFile.close();
}

int main() {
    int x, y, z;
    std::cout << "Enter 3 numbers: ";
    std::cin >> x >> y >> z;

    writeSumAndProductToFile(x, y, z, "task04_output.txt");

    return 0;
}