#include <iostream>

// Abstract class: Animal serves as an interface with a pure virtual function
class Animal
{
public:
    // Pure virtual function makes this class abstract
    virtual void makeSound() const = 0;

    // Virtual destructor for safe cleanup of derived objects
    virtual ~Animal() {}
};

// Derived class: Dog overrides makeSound
class Dog : public Animal
{
public:
    // Polymorphic behavior: the appropriate makeSound() is called based on object type
    void makeSound() const override
    {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Derived class: Cat overrides makeSound
class Cat : public Animal
{
private:
    std::string name;
    int age;

public:
    void makeSound() const override
    {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main()
{
    // Creating objects using pointers to the abstract class Animal
    Animal *myDog = new Dog();
    Animal *myCat = new Cat();

    // Both calls invoke the correct overridden function (polymorphism in action)
    myDog->makeSound(); // Output: Woof! Woof!
    myCat->makeSound(); // Output: Meow! Meow!

    // Free allocated memory
    delete myDog;
    delete myCat;

    return 0;
}