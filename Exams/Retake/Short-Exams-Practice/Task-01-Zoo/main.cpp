#include "Animal.h"
#include "Dog.h"
#include "Zoo.h"
#include <iostream>

void demonstrateZooFunctionality() {
    std::cout << "--- Creating Zoo and Animals ---" << std::endl;
    Zoo myZoo(2); // Създаваме зоопарк с начален капацитет 2

    // Създаваме обекти на стека
    Animal cat("Cat", 2);
    Dog dog("Dog", 5, "Husky");
    Animal bird("Bird", 1);
    
    // Добавяме ги в зоопарка
    std::cout << "\n--- Adding animals to the Zoo ---" << std::endl;
    myZoo.addAnimal(&cat);
    myZoo.addAnimal(&dog);
    myZoo.addAnimal(&bird); // Това ще извика resize()

    std::cout << "\n--- Listing all animals ---" << std::endl;
    myZoo.listAllAnimals();

    std::cout << "\n--- Testing copy constructor ---" << std::endl;
    Zoo anotherZoo = myZoo;

    std::cout << "\n--- Listing animals in the new Zoo ---" << std::endl;
    anotherZoo.listAllAnimals();

    std::cout << "\n--- Program finished, destructors will be called ---" << std::endl;
}

int main() {
    try {
        demonstrateZooFunctionality();
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}