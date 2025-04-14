/*
4. Напишете програма, която чете три цели числа от стандартния вход.
Напишете функция, която приема трите числа и име на файл, в който ще запишете сумата и произведението им.
*/

#include <fstream>
#include <iostream>

bool writeSumAndProductToBinaryFile(int a, int b, int c, const char* filename)
{
    if (!filename)
    {
        std::cerr << "Невалидно име на файл!" << std::endl;
        return false;
    }

    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile.is_open())
    {
        std::cerr << "Грешка при отваряне на бинарен файл: " << filename << std::endl;
        return false;
    }

    int sum = a + b + c;
    int product = a * b * c;

    outFile.write(reinterpret_cast<const char*>(&sum), sizeof(int));
    outFile.write(reinterpret_cast<const char*>(&product), sizeof(int));

    outFile.close();

    return true;
}

bool readSumAndProductFromBinaryFile(const char* filename, int& sum, int& product)
{
    if (!filename)
    {
        std::cerr << "Невалидно име на файл!" << std::endl;
        return false;
    }

    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile.is_open())
    {
        std::cerr << "Грешка при отваряне на бинарен файл: " << filename << std::endl;
        return false;
    }

    inFile.read(reinterpret_cast<char*>(&sum), sizeof(int));
    inFile.read(reinterpret_cast<char*>(&product), sizeof(int));

    inFile.close();

    return true;
}

int main()
{
    std::cout << "Enter 3 numbers: ";
    int x, y, z;
    std::cin >> x >> y >> z;

    if (!writeSumAndProductToBinaryFile(x, y, z, "task04_binary_output.dat"))
    {
        std::cerr << "Неуспешно записване във файл!" << std::endl;
        return 1;
    }

    int sum = 0, product = 0;
    if (!readSumAndProductFromBinaryFile("task04_binary_output.dat", sum, product))
    {
        std::cerr << "Неуспешно четене от файл!" << std::endl;
        return 1;
    }

    std::cout << "Sum: " << sum << "\nProduct: " << product << std::endl;

    return 0;
}