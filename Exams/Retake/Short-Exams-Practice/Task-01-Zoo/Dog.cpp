#include "Dog.h"
#include <cstring>
#include <iostream>

// Parameterized constructor
Dog::Dog(const char* name, int age, const char* breed) : Animal(name, age) {
    if (breed) {
        this->breed = new char[strlen(breed) + 1];
        strcpy(this->breed, breed);
    } else {
        this->breed = nullptr;
    }
    std::cout << "Dog with name " << this->getName() << " created." << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    if (other.breed) {
        this->breed = new char[strlen(other.breed) + 1];
        strcpy(this->breed, other.breed);
    } else {
        this->breed = nullptr;
    }
}

// Assignment operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other); // Call base class assignment

        if (this->breed) {
            delete[] this->breed;
        }

        if (other.breed) {
            this->breed = new char[strlen(other.breed) + 1];
            strcpy(this->breed, other.breed);
        } else {
            this->breed = nullptr;
        }
    }

    return *this;
}

// Destructor
Dog::~Dog() {
    if (this->breed) {
        delete[] this->breed;
        this->breed = nullptr;
    }
    std::cout << "Dog with name " << this->getName() << " - destroyed.\n";
}

// Overridden methods
void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Dog* Dog::clone() const {
    return new Dog(*this);
}