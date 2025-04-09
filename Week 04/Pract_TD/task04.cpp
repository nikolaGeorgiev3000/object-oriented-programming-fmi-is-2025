/*
    Имате двоичния файл people.dat. В него се пази последователно следната информация за произволен брой хора:
        име, което е максимално 23 символа
        каква заплата изкарват от тип unsigned
    Да се имплементират следните функционалности:
        Отпечатване на хората, които изкарват над средната заплата
        Добавяне на човек във файла people.dat
*/
#include <iostream>
#include <fstream>

constexpr size_t MAX_NAME_LENGTH = 24;
constexpr size_t MAX_PEOPLE = 1024;

struct Person {
    char name[MAX_NAME_LENGTH];
    unsigned salary;
};

bool readAllPeople(const char* filename, Person* people, size_t& outCount, size_t maxCount) {
    if (!filename) return false;

    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) return false;

    outCount = 0;
    while (inFile.read(reinterpret_cast<char*>(&people[outCount]), sizeof(Person))) {
        ++outCount;
        if (outCount >= maxCount) break;
    }

    inFile.close();
    return true;
}

double calculateAvgSalary(const Person* people, size_t count) {
    if (count == 0) return 0.0;
    
    unsigned totalSalary = 0;
    for (size_t i = 0; i < count; ++i)
    {
        totalSalary += people[i].salary;
    }
    return static_cast<double>(totalSalary) / count;
}

void printPeopleAboveAvg(const Person* people, size_t count, double avgSalary) {
    std::cout << "People with above " << avgSalary << " salary: " << std::endl;

    for (size_t i = 0; i < count; ++i)
    {
        if (people[i].salary > avgSalary) {
            std::cout << "Person " << i + 1 << ":\n";
            std::cout << people[i].name << ", " << people[i].salary << std::endl;
        }
    }
}

bool printPeopleAboveAvgSalary(const char* filename) {
    if (!filename) return false;

    Person people[MAX_PEOPLE];
    size_t count = 0;

    if (!readAllPeople(filename, people, count, MAX_PEOPLE)) return false;

    if (count == 0) {
        std::cout << "No data" << std::endl;
        return true;
    }

    double avgSalary = calculateAvgSalary(people, count);

    printPeopleAboveAvg(people, count, avgSalary);

    return true;                                                     
}

Person createPerson(const char* name, unsigned salary) {
    Person p;
    strcpy(p.name, name);
    p.salary = salary;

    return p;
}

bool appendPersonToFile(const char* filename, const Person& person) {
    if (!filename) return false;

    std::ofstream ofs(filename, std::ios::binary | std::ios::app);

    if (!ofs.is_open()) return false;

    ofs.write(reinterpret_cast<const char*>(&person), sizeof(Person));

    ofs.close();
    return true;
}

bool addPersonToFile(const char* filename, const char* name, unsigned salary) {
    if (!filename || !name) return false;

    Person p = createPerson(name, salary);
    return appendPersonToFile(filename, p);
}

int main() {
    const char* file = "people.dat";

    addPersonToFile(file, "Ivan Ivanov", 1500);
    addPersonToFile(file, "Petya Petrova", 2200);

    printPeopleAboveAvgSalary(file); 

    return 0;
}