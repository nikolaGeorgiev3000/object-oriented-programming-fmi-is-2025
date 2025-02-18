#include <iostream>

// Abstract class: Animal serves as an interface with a pure virtual function
class Human
{
public:
    // Pure virtual function makes this class abstract
    virtual void analyses() const = 0;

    // Virtual destructor for safe cleanup of derived objects
    virtual ~Human() {}
};

// Derived class: Dog overrides makeSound
class Man : public Human
{
public:
    // Polymorphic behavior: the appropriate makeSound() is called based on object type
    void analyses() const override
    {
        std::cout << "Analysis time!" << std::endl;
    }
};

// Derived class: Cat overrides makeSound
class Woman : public Human
{
private:
    std::string name;
    int age;

public:
    void analyses() const override
    {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main()
{
    // Creating objects using pointers to the abstract class Animal
    Human *myMan = new Man();
    Human *myWoman = new Woman();

    // Both calls invoke the correct overridden function (polymorphism in action)
    myMan->analyses();   // Output: Analysis time!
    myWoman->analyses(); // Output: Meow! Meow!

    // Free allocated memory
    delete myMan;
    delete myWoman;

    return 0;
}