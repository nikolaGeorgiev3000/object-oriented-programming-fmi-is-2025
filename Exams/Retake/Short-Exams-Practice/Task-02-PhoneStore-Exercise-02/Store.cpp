#include "Store.h"

Store::Store(const unsigned BUDGET) : capacity(2), count(0), BUDGET(BUDGET), sumPrices(0)
{
    telephones = new (std::nothrow) Telephone*[capacity];
}

Store::Store(const Store& other)
: BUDGET(other.BUDGET), capacity(other.capacity), count(other.count), sumPrices(other.sumPrices)
{
    copyFrom(other);
}

Store& Store::operator=(const Store& other)
{
    if (this != &other)
    {
        if (BUDGET < other.BUDGET)
        {
            throw std::invalid_argument("Budgets must match!");
        }
        free();
        copyFrom(other);

        capacity = other.capacity;
        count = other.count;
        sumPrices = other.sumPrices;
    }

    return *this;
}

Store::~Store() 
{
    free();
}

// Helper methods
void Store::free()
{
    for (size_t i = 0; i < count; ++i)
    {
        delete telephones[i];
    }
    delete[] telephones;
}

void Store::copyFrom(const Store& other)
{
    telephones = new (std::nothrow) Telephone*[other.capacity];
    for (size_t i = 0; i < count; i++)
    {
        telephones[i] = other.telephones[i]->clone();
    }
}

void Store::resize()
{
    capacity *= 2;

    Telephone** temp = new (std::nothrow) Telephone*[capacity];
    for (size_t i = 0; i < count; ++i)
    {
        temp[i] = telephones[i];
    }

    delete[] telephones;
    telephones = temp;
}

// Public Funct
void Store::print() const
{
    for (size_t i = 0; i < count; ++i)
    {
        telephones[i]->print();
    }   
}

void Store::addTelephone(const Telephone* t)
{
    if (sumPrices + t->getPrice() > BUDGET)
    {
        std::cout << "Telephone cannot be added\n";
        return;
    }
    if (count == capacity)
    {
        resize();
    }
    telephones[count] = t->clone();
    ++count;
    sumPrices += t->getPrice();
}

void Store::removeTelephone(const char* model, const char* brand)
{
    for (size_t i = 0; i < count; ++i)
    {
        if (strcmp(telephones[i]->getModel(), model) == 0 && strcmp(telephones[i]->getBrand(), brand) == 0)
        {
            sumPrices -= telephones[i]->getPrice();
            for (size_t j = i; j < count - 1; j++)
            {
                telephones[j] = telephones[j + 1];
            }
            --count;
            return;
        }
    }
}
