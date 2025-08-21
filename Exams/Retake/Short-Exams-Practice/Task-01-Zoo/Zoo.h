#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

constexpr unsigned MAX_CAPACITY = 64;

class Zoo {
public:
    Zoo(unsigned capacity = MAX_CAPACITY);

    Zoo(const Zoo& other);

    Zoo& operator=(const Zoo& other);

    ~Zoo();

    // Other public methods
    void addAnimal(const Animal* animalToAdd);

    void listAllAnimals() const;

private:
    Animal** animals;
    unsigned capacity;
    unsigned count;

    // Helper methods
    void resize();
    void copyFrom(const Zoo& other);
    void free();
};

#endif // ZOO_H