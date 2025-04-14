#include <cstring>
#include <iostream>

struct Person
{
    char firstName[16];
    char lastName[16];
    unsigned short age;
};

Person createPerson(const char* fName, const char* lName, const unsigned short parAge)
{
    Person toReturn;
    strcpy(toReturn.firstName, fName);
    strcpy(toReturn.lastName, lName);
    toReturn.age = parAge;

    return toReturn;
}

void printPerson(const Person& p)
{
    std::cout << "Person: " << p.firstName << " " << p.lastName << ", " << p.age << " years old." << std::endl;
}

int main()
{
    Person p1 = createPerson("John", "Doe", 30);
    Person* p2 = new Person(createPerson("Jane", "Doe", 25));

    printPerson(p1);
    printPerson(*p2);

    // Clear the memory
    delete p2;
    return 0;
}