#include "Smartphone.h"

Smartphone::Smartphone(const char* OS, unsigned memory, const char* model, const char* brand, double price) 
: Telephone(model, brand, price + memory) 
{
    setOS(OS);
    setMemory(memory);
}

Smartphone::Smartphone(const Smartphone& other) : Telephone(other) 
{
    setOS(other.OS);
    setMemory(other.memory);
}

Smartphone& Smartphone::operator=(const Smartphone& other) 
{
    if (this != &other) 
    {
        Telephone::operator=(other);

        delete[] OS;

        setOS(other.OS);
        setMemory(other.memory);
    }

    return *this;
}

Smartphone::~Smartphone() 
{
    delete[] OS;
}

// Setters
void Smartphone::setOS(const char* newOS) 
{
    if (!newOS) 
    {
        throw std::invalid_argument("Invalid OS to set");
    }
    OS = new char[strlen(newOS) + 1];
    strcpy(OS, newOS);
}

void Smartphone::setMemory(unsigned newMemory) 
{
    memory = newMemory;
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

// Clone Method
Smartphone* Smartphone::clone() const 
{
    return new Smartphone(*this);
}

void Smartphone::print(std::ostream& ofs) const 
{
    ofs << "Smartphone: " << OS << ", " << memory << " is a: ";
    Telephone::print(ofs);
}