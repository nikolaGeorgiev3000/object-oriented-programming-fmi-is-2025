#include "Animal.h"
#include <cstring>
#include <iostream>

// Parameterized Constructor
Animal::Animal(const char* name, int age) : age(age) {
    if (name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    } else {
        this->name = nullptr;
    }

    std::cout << "Animal with name " << this->getName() << " created." << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal& other) {
    this->copyFrom(other);
}

// Assignment Operator
Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->cleanup();       // Delete old data
        this->copyFrom(other); // Assign new data
    }
    return *this;
}

// Virtual Destructor
Animal::~Animal() {
    this->cleanup();
    std::cout << "Animal with name " << (this->name ? this->name : "N/A")
              << " destroyed.\n";
}

// Helper method for memory allocation and copying
void Animal::copyFrom(const Animal& other) {
    if (other.name) { // If it's a valid name
        this->name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    } else {
        this->name = nullptr;
    }
    this->age = other.age;
}

// Helper method to free memory
void Animal::cleanup() {
    // Check whether it's a valid pointer
    if (this->name) {
        delete[] this->name;
        this->name = nullptr; // Prevent hanging pointers
    }
}

// Virtual Methods
void Animal::makeSound() const {
    std::cout << "Default animal sound: Rwraaaar\n";
}

Animal* Animal::clone() const {
    return new Animal(*this);
}

// Getter
const char* Animal::getName() const {
    return this->name;
}
