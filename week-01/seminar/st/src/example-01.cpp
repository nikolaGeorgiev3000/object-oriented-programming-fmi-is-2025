#include <cstring>
#include <iostream>

struct Point
{
    double x;
    double y;
};

struct Person
{
    char firstName[16];
    char lastName[16];
    unsigned short age;
};

void printPerson(const Person& p) // Const reference to avoid modifying the person
{
    std::cout << "Person: " << p.firstName << " " << p.lastName << ", " << p.age << " years old." << std::endl;
}

void setAgeRef(Person& p, unsigned short newAge) // Reference to modify the person
{
    p.age = newAge;
}

void setAgeCopy(Person p)
{
    p.age = 15;
}

void setAgePtr(Person* p, unsigned short newAge)
{
    if (p)
    {
        p->age = newAge;
    }
}

int main()
{
    Point start;
    start.x = 0.0;
    start.y = 0.0;

    Person* p1 = new Person();
    strcpy(p1->firstName, "John");
    strcpy(p1->lastName, "Doe");
    p1->age = 30;

    printPerson(*p1);

    setAgeRef(*p1, 31);
    printPerson(*p1);

    setAgeCopy(*p1); // This will not change the age of the person
    printPerson(*p1);

    setAgePtr(p1, 32); // This will change the age of the person
    printPerson(*p1);

    // Clear the heap memory
    delete p1;

    return 0;
}