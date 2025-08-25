#include "Smartphone.h"

Smartphone::Smartphone(const char* OS, unsigned memory, const char* model, const char* brand, double price)
: Telephone(model, brand, price)
{
    setOS(OS);
    setMem(memory);
}
    


Smartphone::Smartphone(const Smartphone& other)
: Telephone(other)
{
    copyFrom(other);
}

Smartphone& Smartphone::operator=(const Smartphone& other)
{
    if (this != &other)
    {
        Telephone::operator=(other);
        
        free();
        copyFrom(other);
    }
    return *this;
}
Smartphone::~Smartphone() 
{
    free();
}

// Public funct
void Smartphone::print() const
{
    std::cout << "Smartphone: " << OS << ", " << memory << " GB is a: ";
    Telephone::print();
}

Smartphone* Smartphone::clone() const
{
    return new Smartphone(*this);
}

// Getters
const char* Smartphone::getOS() const
{
    return this->OS;
}
    
unsigned Smartphone::getMem() const
{
    return this->memory;
}

// Setters
void Smartphone::setOS(const char* newOS)
{
    if (!newOS)
    {
        throw std::invalid_argument("Invalid new OS");
    }

    OS = new char[strlen(newOS) + 1];
    strcpy(OS, newOS);
}

void Smartphone::setMem(unsigned newMemory)
{
    memory = newMemory;
}

// Helper methods
void Smartphone::free()
{
    delete[] OS;
    OS = nullptr;
}

void Smartphone::copyFrom(const Smartphone& other)
{
    setOS(other.OS);
    setMem(other.memory);
}