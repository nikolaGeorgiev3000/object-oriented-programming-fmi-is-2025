#include <cstring>
#include <fstream>
#include <iostream>

constexpr size_t MAX_NAME_LENGTH = 25;

struct Student
{
    char name[MAX_NAME_LENGTH];
    unsigned age;
    float height;
};

Student createStudent(const char* name, unsigned age, float height)
{
    Student toReturn;

    strcpy(toReturn.name, name);
    toReturn.age = age;
    toReturn.height = height;

    return toReturn;
}

void serializeStudent(std::ofstream& outFile, const Student& student)
{
    outFile.write(reinterpret_cast<const char*>(&student), sizeof(student));
}

void deserializeStudent(std::ifstream& inFile, Student& st)
{
    inFile.read(reinterpret_cast<char*>(&st), sizeof(st));
}

void printStudent(const Student& st)
{
    std::cout << "Student info: " << st.name << ", " << st.age << ", " << st.height << "\n";
}

int main()
{
    {
        Student st = createStudent("Ivo", 22, 1.87f);

        std::ofstream outFile("log.dat", std::ios::binary);
        serializeStudent(outFile, st);
    }

    {
        Student st1;
        std::ifstream inFile("log.dat", std::ios::binary);
        deserializeStudent(inFile, st1);
        printStudent(st1);
    }
}
