#include "Smartphone.h"


// Big Four
Smartphone::Smartphone(const char* os, unsigned memory, 
                       const char* newModel, const char* newBrand, double newPrice) 
                       : memory(memory), Telephone(newModel, newBrand, newPrice + memory) {
    setOs(os);
}

Smartphone::Smartphone(const Smartphone& other) : memory(other.memory), Telephone(other) {
    setOs(other.os);
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        Telephone::operator=(other);

        delete[] os;

        setOs(other.os);
        setMemory(other.memory);
    }

    return *this;
}

Smartphone::~Smartphone() {
    delete[] os;
}

// Getters
const char* Smartphone::getOs() const {
    return this->os;
}

unsigned Smartphone::getMemory() const {
    return this->memory;
}

// Setters
void Smartphone::setOs(const char* newOs) {
    if (!newOs) {
        throw std::invalid_argument("OS must not be null");
    }

    os = new char[strlen(newOs) + 1];
    strcpy(os, newOs);
}

void Smartphone::setMemory(unsigned newMemory) {
    memory = newMemory;
}

// Other Public Functionality
void Smartphone::print(std::ostream& ofs) const {
    ofs << "Smartphone: " << os << ", " << memory << " is a ";
    Telephone::print(ofs);
}

// Clone Function
Smartphone* Smartphone::clone() const {
    return new Smartphone(*this);
}