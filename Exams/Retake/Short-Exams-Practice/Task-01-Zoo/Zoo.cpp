#include "Zoo.h"
#include <iostream>

// Param. ctor
Zoo::Zoo(unsigned capacity) : capacity(capacity), count(0) {
    if (capacity > 0) {
        animals = new (std::nothrow) Animal*[capacity];

        // If there is an error with dynamic allocation
        if (!animals) {
            throw std::bad_alloc();
        }
    } else {
        animals = nullptr;
    }
}

// Copy constructor
Zoo::Zoo(const Zoo& other) {
    copyFrom(other);
}

// Destructor
Zoo::~Zoo() {
    free();
    std::cout << "Zoo destroyed." << std::endl;
}

// Assignment operator
Zoo& Zoo::operator=(const Zoo& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

// Помощен метод за освобождаване на паметта
void Zoo::free() {
    for (unsigned i = 0; i < count; ++i) {
        if (animals[i]) {
            delete animals[i];
            animals[i] = nullptr;
        }
    }

    delete[] animals;
    animals = nullptr;
    capacity = 0;
    count = 0;
}

// Помощен метод за копиране
void Zoo::copyFrom(const Zoo& other) {
    capacity = other.capacity;
    count = other.count;
    animals = new (std::nothrow) Animal*[capacity];

    if (!animals)
        throw std::bad_alloc();

    for (unsigned i = 0; i < count; ++i) {
        if (other.animals[i]) {
            animals[i] = other.animals[i]->clone(); // Deep copy
        } else {
            animals[i] = nullptr;
        }
    }
}

// Помощен метод за оразмеряване
void Zoo::resize() {
    std::cout << "Resize called.\n";
    unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;
    Animal** newAnimals = new (std::nothrow) Animal*[newCapacity];

    if (!newAnimals) {
        throw std::bad_alloc();
    }

    for (unsigned i = 0; i < count; ++i) {
        newAnimals[i] = animals[i];
    }

    delete[] animals;
    animals = newAnimals;
    capacity = newCapacity;
}

// Публичен метод за добавяне на животно
void Zoo::addAnimal(const Animal* animalToAdd) {
    if (count >= capacity) {
        resize();
    }

    animals[count] = animalToAdd->clone(); // Use clone() method to add a deep copy of the object
    ++count;
    std::cout << "Animal named " << animalToAdd->getName() << " added.\n";
}

void Zoo::listAllAnimals() const {
    for (unsigned i = 0; i < count; ++i)
    {
        std::cout << "Animal named " << animals[i]->getName() << " says: ";
        animals[i]->makeSound(); // Polymorphic call
    }
}
