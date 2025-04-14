#ifndef BOOK_HPP
#define BOOK_HPP

#include "Utility.hpp"

class Book
{
  public:
    // Big Four
    Book(const char*, const char*, unsigned int);
    Book(const Book&);
    Book& operator=(const Book&);
    ~Book();

    // Getters
    const char* getName() const;
    const char* getAuthor() const;
    unsigned int getPages() const;
    const char* getID() const;

    // Setters
    void setName(const char*);
    void setAuthor(const char*);

    // Streams text-files work
    void writeToFile(std::ostream&) const;
    void readFromFile(std::istream&);

    // Operators (for user-io operations)
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);

  private:
    char* name = nullptr;
    char* author = nullptr;
    unsigned int pages;
    char identifier[Constants::ID_LEN];
    static unsigned int idCounter;

    void copyDynamic(const Book&);
    void freeDynamic();
    void generateID();
};

#endif