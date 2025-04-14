#include <fstream>

#include "Book.hpp"

int main()
{
    try
    {
        std::ofstream outFile("books.txt");
        if (!outFile)
        {
            std::cerr << "Неуспешно отваряне на файл за писане.\n";
            return 1;
        }

        Book original("Малкият принц", "Антоан дьо Сент-Екзюпери", 96);

        original.writeToFile(outFile);

        Book copy(original); // Create a copy

        copy.setName("Големият принц"); // Change the copy
        copy.setAuthor("Аз");

        copy.writeToFile(outFile); // Write the copy, he-he

        outFile.close();

        std::cout << "\n\nКнига (извеждане с <<):\n";
        std::cout << original << '\n';
        std::cout << copy << "\n\n";

        // Зареждаме книга от файл
        std::ifstream inFile("books.txt");
        if (!inFile)
        {
            std::cerr << "Неуспешно отваряне на файл за четене.\n";
            return 1;
        }

        Book loaded("dummy", "dummy", 0); // dummy данни, ще се презапишат
        Book loadedCopy(loaded);

        loaded.readFromFile(inFile);
        loadedCopy.readFromFile(inFile);
        inFile.close();

        // Извеждаме заредената книга
        std::cout << "\n\nЗаредена книга от файл:\n";
        std::cout << loaded << "\n";
        std::cout << loadedCopy << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}