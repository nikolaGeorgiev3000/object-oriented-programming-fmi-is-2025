#include "Store.h"

Store::Store(const unsigned BUDGET) : capacity(2), count(0), BUDGET(BUDGET), sumPrices(0)
{
    tels = new (std::nothrow) Telephone*[capacity];
}

Store::Store(const Store& other) : BUDGET(other.BUDGET)
{
    copyFrom(other);
}

Store& Store::operator=(const Store& other)
{
    if (this != &other)
    {
        if (BUDGET < other.BUDGET)
        {
            throw std::invalid_argument("The right store's budget is bigger");
        }

        free();
        copyFrom(other);
    }
    return *this;
}

Store::~Store()
{
    free();
}

// Public funct
void Store::print() const
{
    for (size_t i = 0; i < count; i++)
    {
        tels[i]->print();
    }
}

bool Store::addTelephone(const Telephone* t)
{
    if (!t)
    {
        throw std::invalid_argument("Invalid telephone to add");
    }

    if (sumPrices + t->getPrice() > BUDGET)
    {
        std::cout << "Store Budget limitations\n";
        return false;
    }

    if (count == capacity)
    {
        resize();
    }

    tels[count] = t->clone();
    ++count;
    sumPrices += t->getPrice();
    return true;
}

bool Store::removeTelephone(const char* model, const char* brand)
{
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(tels[i]->getModel(), model) == 0 && strcmp(tels[i]->getBrand(), brand) == 0) 
        {
            sumPrices -= tels[i]->getPrice();

            for (size_t j = i; j < count - 1; j++)
            {
                tels[j] = tels[j + 1];
            }

            --count;
            return true;
        }
    }
    return false; // Telephone not found
}

// Helper methods
void Store::free()
{
    for (size_t i = 0; i < count; i++)
    {
        delete tels[i];
    }
    delete[] tels;
}

void Store::copyFrom(const Store& other)
{
    capacity = other.capacity;
    sumPrices = other.sumPrices;

    tels = new (std::nothrow) Telephone*[capacity];

    for (size_t i = 0; i < other.count; i++)
    {
        tels[i] = other.tels[i]->clone();
        ++count;
    }
}

void Store::resize()
{
    capacity *= 2; // We ignore the option where capacity is initially set to 0

    Telephone** temp = new (std::nothrow) Telephone*[capacity];

    for (size_t i = 0; i < count; i++)
    {
        temp[i] = tels[i];
    }

    delete[] tels;
    tels = temp;
}
