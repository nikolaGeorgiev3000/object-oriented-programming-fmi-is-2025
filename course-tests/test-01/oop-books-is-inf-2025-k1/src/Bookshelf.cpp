#include "Bookshelf.hpp"

static unsigned int currentBookCount = 0;

// `Shelf` implementations
bool Bookshelf::Shelf::isInside(const Book* bookToCheck) const
{
    for (size_t i = 0; i < bookCount; ++i)
    {
        if (bookToCheck == books[i])
        {
            return true; // It's already in the shelf
        }
    }
    return false;
}

void Bookshelf::Shelf::addBook(Book* newBook)
{
    if (!newBook)
    {
        throw std::invalid_argument("Invalid book.");
    }

    if (isInside(newBook))
    {
        std::cerr << "This book is already in this shelf!\n";
        return;
    }

    if (bookCount >= capacity)
    {
        Utils::resizePointerArray(books, capacity);
    }

    books[bookCount++] = newBook;
    totalPages += newBook->getPages();
}

bool Bookshelf::Shelf::removeBook(Book* bookToRemove)
{
    if (!bookToRemove)
    {
        throw std::invalid_argument("Invalid book.");
    }
    if (bookCount == 0)
    {
        throw std::logic_error("No books to remove from this shelf.");
    }
    for (size_t i = 0; i < bookCount; ++i)
    {
        if (books[i] == bookToRemove)
        {
            totalPages -= bookToRemove->getPages();
            Utils::shiftLeftFromIndex(books, bookCount, i);
            return true;
        }
    }
    return false; // Book not found in this shelf.
}

Book* Bookshelf::Shelf::findBookByName(const char* bookName) const
{
    if (!bookName)
    {
        throw std::invalid_argument("Invalid book name!");
    }

    for (size_t i = 0; i < bookCount; ++i)
    {
        if (std::strcmp(books[i]->getName(), bookName) == 0)
        {
            return books[i]; // Book found, return pointer to it.
        }
    }

    return nullptr;
}

void Bookshelf::Shelf::free()
{
    delete[] books; // Delete only the pointer to the array of pointers, do not touch the books!
    books = nullptr;
    bookCount = 0;
    capacity = 0;
    totalPages = 0;
}

void Bookshelf::Shelf::resize(unsigned int newMaxPages)
{
    size_t i = 0;
    unsigned int newTotalPages = 0;

    while (i < bookCount)
    {
        unsigned int currBookPages = books[i]->getPages();
        if (newTotalPages + currBookPages > newMaxPages)
        {
            Utils::shiftLeftFromIndex(books, bookCount, i); // New book on `i`, so we don't increment it.
        }
        else
        {
            newTotalPages += currBookPages;
            ++i;
        }
    }
    totalPages = newTotalPages;
}

// `Bookshelf` implementations

// Constructor & destructor
Bookshelf::Bookshelf(unsigned int _shelfCount, unsigned int _maxPagesPerShelf)
    : shelfCount(_shelfCount), maxPagesPerShelf(_maxPagesPerShelf)
{
    shelves = new Shelf[shelfCount];
}

Bookshelf::~Bookshelf()
{
    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        shelves[i].free(); // Clear all the shelves without deleting the books.
    }

    delete[] shelves;
    shelves = nullptr;
}

// Functionalities
void Bookshelf::addBook(Book& bookToAdd)
{
    if (currentBookCount == MAX_BOOKS)
    {
        std::cout << "Maximum number of books reached!\n";
        return;
    }

    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        if (shelves[i].totalPages + bookToAdd.getPages() <= maxPagesPerShelf)
        {
            shelves[i].addBook(&bookToAdd);
            ++currentBookCount;
        }
    }

    std::cout << "No suitable shelf found for the book.\n";
    return;
}

Book* Bookshelf::findBookByName(const char* bookName) const
{
    if (!bookName)
    {
        throw std::invalid_argument("Invalid book name!");
    }

    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        Book* result = shelves[i].findBookByName(bookName);

        if (result)
            return result;
    }

    return nullptr;
}

void Bookshelf::removeBook(Book& bookToRemove)
{

    const char* bookName = bookToRemove.getName();
    bool isRemoved = false;

    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        Book* temp = shelves[i].findBookByName(bookToRemove.getName());

        if (temp)
        {
            isRemoved = shelves[i].removeBook(temp);
            if (isRemoved)
            {
                --currentBookCount;
                break;
            }
        }
    }
    if (isRemoved)
    {
        std::cout << "Book successfully removed!\n";
    }
    std::cout << "Book not removed!\n";
}

void Bookshelf::resizeShelves(unsigned int newMaxPages)
{
    maxPagesPerShelf = newMaxPages;

    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        shelves[i].resize(newMaxPages);
    }
}

void Bookshelf::print() const
{
    for (unsigned int i = 0; i < shelfCount; ++i)
    {
        for (size_t j = 0; j < shelves[i].bookCount; ++j)
        {
            std::cout << *(shelves[i].books[j]) << " | "
                      << "Shelf: " << i << ", Position: " << j << '\n';
        }
    }
}