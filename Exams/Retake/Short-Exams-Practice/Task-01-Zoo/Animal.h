#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
    // Constructor with parameters
    Animal(const char* name, int age);

    // Copy constructor
    Animal(const Animal& other);

    // Assignment operator
    Animal& operator=(const Animal& other);

    // Virtual destructor
    virtual ~Animal();

    // Virtual method for sound
    virtual void makeSound() const;

    // Virtual method for cloning
    virtual Animal* clone() const;

    // Other methods (if needed)
    const char* getName() const;

protected:
    // Member data
    char* name;
    int age;

private:
    // Helper method for copying
    void copyFrom(const Animal& other);

    // Helper method for cleanup
    void cleanup();
};

#endif // ANIMAL_H
