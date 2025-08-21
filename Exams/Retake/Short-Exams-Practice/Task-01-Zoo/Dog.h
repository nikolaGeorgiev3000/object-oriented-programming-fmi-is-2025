#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    // Parameterized constructor
    Dog(const char* name, int age, const char* breed);

    // Copy constructor
    Dog(const Dog& other);

    // Assignment operator
    Dog& operator=(const Dog& other);

    // Destructor
    ~Dog() override;

    // Overridden methods
    void makeSound() const override;

    Dog* clone() const override;

private:
    char* breed;
};

#endif // DOG_H