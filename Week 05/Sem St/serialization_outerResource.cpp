#include <iostream>
#include <cstring>
#include <fstream>

#pragma warning (disable: 4996)

// constexpr size_t MAX_NAME_LENGTH = 25;

struct Student {
    char* name = nullptr;
    unsigned age;
    float height;
};

Student createStudent(const char* name, unsigned age, float height) {
    Student toReturn;

    size_t length = strlen(name);
    toReturn.name = new char[length + 1];

    strcpy(toReturn.name, name);
    toReturn.age = age;
    toReturn.height = height;

    return toReturn;
}

void freeStudent(Student& st) {
    delete[] st.name;
}

void serializeStudent(std::ofstream& outFile, const Student& st) {
    // Write: nameLen, name, and the rest of member-data
    size_t nameLen = strlen(st.name);
    outFile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
    outFile.write(st.name, nameLen);
    outFile.write(reinterpret_cast<const char*>(&st.age), sizeof(st.age));
    outFile.write(reinterpret_cast<const char*>(&st.height), sizeof(st.height));
}

Student deserializeStudent(std::ifstream& inFile) {
    Student st;

    size_t nameLen = 0;
    inFile.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
    
    st.name = new char[nameLen + 1]{};
    inFile.read(st.name, nameLen);
    st.name[nameLen] = '\0';

    inFile.read(reinterpret_cast<char*>(&st.age), sizeof(st.age));
    inFile.read(reinterpret_cast<char*>(&st.height), sizeof(st.height));

    return st;
}

void printStudent(const Student& st) {
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
