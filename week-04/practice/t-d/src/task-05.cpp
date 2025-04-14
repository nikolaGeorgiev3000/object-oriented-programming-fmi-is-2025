/*
    Да се направи функция, която "разшифрова" скрито съобщение.
    Съобщението представлява двоичен файл с неизвестна дължина.
    Това, което съхранява е поредица от цели неотрицателни числа.
    "Ключът" за съобщението се съхранява в друг двоичен файл и
    представлява число в интервала [0, 255].
    Преценете как е най-подходящо да прочетете и съхраните ключа.

    Шифърът за получаване на правилното съобщение е към всяко число
    от прочетения файл, съдържащ съобщението да се добави стойността на прочетения ключ

    Пояснение: ако файлът със скритото съобщение след прочитане изглежда така: 23 48 3 12 4006
    А файлът, съдържащ ключа има стойност 2, то разшифрованото съобщение трябва да е: 25 50 5 14 4008

    Изведете разшифрованото съобщение на конзолата.
    Пояснение 2: функцията ви трябва да има следната сигнатура

        void decypherMessage(const char* rawMessageFileName, const char* keyFileName )
*/
#include <fstream>
#include <iostream>

void decypherMessage(const char* rawMessageFilename, const char* keyFilename)
{
    if (!rawMessageFilename || !keyFilename)
    {
        std::cerr << "Invalid filenames.\n";
        return;
    }

    // Read the key
    std::ifstream in1(keyFilename, std::ios::binary);

    if (!in1.is_open())
        return;

    unsigned char keyValue; // [0, 255]

    in1.read(reinterpret_cast<char*>(&keyValue), sizeof(keyValue));

    in1.close();

    // Read the values & do calculations
    std::ifstream in2(rawMessageFilename, std::ios::binary);

    if (!in2.is_open())
        return;

    unsigned int value = 0;

    std::cout << "Raw msg: \n";

    while (in2.read(reinterpret_cast<char*>(&value), sizeof(value)))
    {
        std::cout << value << " ";
    }

    in2.clear();
    std::cout << "\n\nRead: " << in2.tellg() << " bytes!\n";
    in2.seekg(0, std::ios::beg);

    std::cout << "\nDecyphered msg: \n";

    while (in2.read(reinterpret_cast<char*>(&value), sizeof(value)))
    {
        std::cout << (value + keyValue) << " ";
    }
    std::cout << std::endl;

    in2.close();
}

int main()
{
    decypherMessage("encrypted.dat", "key.dat");

    return 0;
}