#include <iostream>

struct Book
{
    double price;
    char genre;
    int copiesCount;
    bool isSoldOut;
};

bool areEqual(const Book& b1, const Book& b2)
{
    return b1.price == b2.price && 
        b1.genre == b2.genre && 
        b1.copiesCount == b2.copiesCount && 
        b1.isSoldOut == b2.isSoldOut;
}

void createBook(Book& b)
{
    std::cout << "Enter price, genre, copies count, and isSoldOut (0 or 1):\n";
    std::cin >> b.price >> b.genre >> b.copiesCount;

    int soldOut;
    std::cin >> soldOut;
    b.isSoldOut = (soldOut != 0); // Convert int to bool
}

void printBook(const Book& b)
{
    std::cout << "Price: " << b.price;
    std::cout << "\nGenre: " << b.genre;
    std::cout << "\nSold copies: " << b.copiesCount;
    std::cout << "\nSold?: " << std::boolalpha << b.isSoldOut;
    std::cout << std::endl;
}

int main()
{
    Book b;
    createBook(b);
    printBook(b);

    Book* bookPtr = &b;
    std::cout << "\nPointer access to genre: " << bookPtr->genre << std::endl;

    return 0;
}