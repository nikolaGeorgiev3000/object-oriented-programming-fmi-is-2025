#ifndef BOOKSHELF_HPP
#define BOOKSHELF_HPP

#include "Book.hpp"

class Bookshelf
{
  public:
    // Big Four
    Bookshelf(unsigned int, unsigned int);
    ~Bookshelf();

    // Forbid copying, by condition
    Bookshelf(const Bookshelf&) = delete;
    Bookshelf& operator=(const Bookshelf&) = delete;

    // Functionality
    void addBook(Book&); // Добавя книга на най-ниския възможен рафт
    void removeBook(Book&);
    Book* findBookByName(const char*) const;

    void resizeShelves(unsigned int); // Променя лимита на страници на всеки рафт, изхвърля неподходящите книги
    void print() const;

  private:
    struct Shelf
    {
      public:
        friend class Bookshelf; // Allow the wrapper-class to access inner class' private data

        void addBook(Book*);
        bool removeBook(Book*);
        Book* findBookByName(const char*) const; // Find a book by name

      private:
        Book** books = nullptr; // Use array of pointers in order to avoid forbidden copying
        size_t bookCount = 0;
        size_t capacity = 0;
        unsigned int totalPages = 0;

        bool isInside(const Book*) const;
        void free();
        void resize(unsigned int);
    };

    Shelf* shelves = nullptr;
    unsigned int shelfCount = 0;
    unsigned int maxPagesPerShelf = 0;

    static constexpr unsigned int MAX_BOOKS = Constants::MAX_BOOKS;
    static unsigned int currentBookCount;
};

#endif