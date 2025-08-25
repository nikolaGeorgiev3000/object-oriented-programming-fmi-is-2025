#include "Smartphone.h"

Smartphone::Smartphone(const char* OS, unsigned memory, const char* model, const char* brand, double price)
: Telephone(model, brand, price + memory)
{
    setOS(OS);
    setMemory(memory);
}

Smartphone::Smartphone(const Smartphone& other) 
: Telephone(other)
{
    setOS(other.OS); 
    setMemory(other.memory);
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

// Helper methods
void Smartphone::free()
{
    delete[] OS;
}

void Smartphone::copyFrom(const Smartphone& other)
{
    setOS(other.OS);
    setMemory(other.memory);
}

// Getters
const char* Smartphone::getOS() const
{
    return this->OS;
}

unsigned Smartphone::getMemory() const
{
    return this->memory;
}

// Setters
void Smartphone::setOS(const char* newOS) 
{
    try 
    {
        OS = new char[strlen(newOS) + 1];
        strcpy(OS, newOS);
    } catch (std::exception& e)
    {
        std::cout << "Wrong new OS: " << e.what() << std::endl;
    }
}

void Smartphone::setMemory(unsigned newMemory)
{
    memory = newMemory;
}

void Smartphone::print() const
{
    std::cout << "Smartphone: " << OS << ", " << memory << " is a ";
    Telephone::print();
}

// Clone funct
Smartphone* Smartphone::clone() const
{
    return new Smartphone(*this);
}