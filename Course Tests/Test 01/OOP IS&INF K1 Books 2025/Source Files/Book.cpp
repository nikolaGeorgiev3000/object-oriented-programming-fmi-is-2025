#include "Book.hpp"

constexpr size_t STARTING_ID = 0;
unsigned int Book::idCounter = STARTING_ID;

// Big Four
Book::Book(const char* _bookName, const char* _authorName, unsigned int _pages) : pages(_pages)
{
    setName(_bookName);
    setAuthor(_authorName);
    generateID();
}

Book::Book(const Book& other) : pages(other.pages)
{
    setName(other.name);
    setAuthor(other.author);
    generateID(); // Different ID
}

Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        freeDynamic();
        copyDynamic(other);
        pages = other.pages;
    }

    return *this;
}

Book::~Book()
{
    freeDynamic();
}

// Getters
const char* Book::getName() const
{
    return name;
}
const char* Book::getAuthor() const
{
    return author;
}
unsigned int Book::getPages() const
{
    return pages;
}
const char* Book::getID() const
{
    return identifier;
}

// Setters
void Book::setName(const char* _bookName)
{
    if (!Utils::isValidString(_bookName))
    {
        throw std::invalid_argument("Invalid book name!");
    }
    if (name)
    { // Safe update of the book's name in existing book
        delete[] name;
        name = nullptr;
    }

    size_t bookNameLen = strlen(_bookName) + 1;
    name = new char[bookNameLen];
    strcpy(name, _bookName);
}

void Book::setAuthor(const char* _authorName)
{
    if (!Utils::isValidString(_authorName))
    {
        throw std::invalid_argument("Invalid author name!");
    }
    if (author)
    { // Safe update of the author's name in existing book
        delete[] author;
        author = nullptr;
    }

    size_t authorNameLen = strlen(_authorName) + 1;
    author = new char[authorNameLen];
    strcpy(author, _authorName);
}

// Functions for working with text file streams
void Book::writeToFile(std::ostream& os) const
{
    os << name << ';'
       << author << ';'
       << pages << ';'
       << identifier << '\n';
}
void Book::readFromFile(std::istream& is)
{
    char* tempNameBuffer = Utils::readDynamicString(is);   // Dynamically reads and allocates memory for the book's name from the input stream.
    char* tempAuthorBuffer = Utils::readDynamicString(is); // Dynamically reads and allocates memory for the author's name from the input stream.

    unsigned int tempPages;
    is >> tempPages;
    is.ignore(); // Get the delimiter ';'

    char tempIdentifier[Constants::ID_LEN];
    is.getline(tempIdentifier, Constants::ID_LEN);

    setName(tempNameBuffer);
    setAuthor(tempAuthorBuffer);
    pages = tempPages;

    Utils::safeCopy(identifier, tempIdentifier, Constants::ID_LEN);

    delete[] tempNameBuffer;
    delete[] tempAuthorBuffer;
}

// Operators (for user-io operations)
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.name << ';'
       << book.author << ';'
       << book.pages << ';'
       << book.identifier;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    char* tempNameBuffer = Utils::readDynamicString(is);
    char* tempAuthorBuffer = Utils::readDynamicString(is);

    unsigned int tempPages;
    is >> tempPages;
    is.ignore();

    book.setName(tempNameBuffer);
    book.setAuthor(tempAuthorBuffer);
    book.pages = tempPages;

    delete[] tempNameBuffer;
    delete[] tempAuthorBuffer;

    return is;
}

// Private helpers
void Book::copyDynamic(const Book& other)
{
    setName(other.name);
    setAuthor(other.author);
}

void Book::freeDynamic()
{
    delete[] name;
    delete[] author;
    name = author = nullptr;
}
void Book::generateID()
{
    std::snprintf(identifier, Constants::ID_LEN, "IS-INF-%04u", ++idCounter);
}