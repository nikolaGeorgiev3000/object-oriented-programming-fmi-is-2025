#include "Store.h"

// Helper Methods
void Store::free() 
{
    for (size_t i = 0; i < count; ++i) 
    {
        delete telephones[i];
    }

    delete[] telephones;
    telephones = nullptr;
}

void Store::copyFrom(const Store& other) 
{
    if (BUDGET != other.BUDGET) 
    {
        throw std::invalid_argument("Budgets of the stores do not match");
    }

    while (capacity < other.capacity) 
    {
        resize();
    }

    count = 0;  // Reset count before copying
    currentSumTelephones = other.currentSumTelephones;

    for (size_t i = 0; i < other.count; ++i) 
    {
        telephones[i] = other.telephones[i]->clone();
        ++count;
    }
}

void Store::resize() 
{
    unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;

    delete[] telephones;
    telephones = new (std::nothrow) Telephone*[newCapacity];
    capacity = newCapacity;
}

// Big Four
Store::Store(const unsigned BUDGET) : count(0), capacity(INIT_CAPACITY), BUDGET(BUDGET), currentSumTelephones(0) 
{
    telephones = new (std::nothrow) Telephone*[capacity];
    std::cout << "Store created\n";
}

Store::Store(const Store& other) : BUDGET(other.BUDGET) 
{
    copyFrom(other);
}

Store& Store::operator=(const Store& other) 
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Store::~Store() 
{
    free();
    std::cout << "Store destroyed\n";
}

// Functionality
void Store::print(std::ostream& ofs) const 
{
    for (size_t i = 0; i < count; ++i) 
    {
        telephones[i]->print(ofs);
    }   
}

void Store::addTelephone(const Telephone* telephoneToAdd) 
{
    if (currentSumTelephones + telephoneToAdd->getPrice() > BUDGET)
    {
        std::cout << "You cannot add " << telephoneToAdd->getModel() << " to the store due to Budget limitations.\n";
        return;
    }
    if (count == capacity) 
    {
        resize();
    }

    telephones[count] = telephoneToAdd->clone();
    ++count;
    currentSumTelephones += telephoneToAdd->getPrice();   
}

void Store::removeTelephone(const char* model, const char* brand) {
    for (size_t i = 0; i < count; ++i)
    {
        if (strcmp(telephones[i]->getModel(), model) == 0 && strcmp(telephones[i]->getBrand(), brand) == 0)
        {
            currentSumTelephones -= telephones[i]->getPrice();

            for (size_t j = i; j < count - 1; ++j)
            {
                telephones[j] = std::move(telephones[j + 1]);
            }
            
            --count;
            return;
        }
    }
    std::cout << "No such telephone found in the store.\n";
}
