#include <iostream>
#include <cstring>
#include <assert.h>

const int STUDENT_MAX_SIZE = 10;

enum class Major
{
    undefined, Inf, InfS, Cs, S
};

const char* getMajorStr(Major m)
{
    switch (m)
    {
        case Major::Inf : return "Inf";
        case Major::InfS : return "InfS";
        case Major::Cs : return "Cs";
        case Major::S : return "S";
        case Major::undefined : return "undefined";
    }

    return "";
}

struct Student
{
    char name[100] = "";
    unsigned fn = 0;
    Major major = Major::undefined;

    // Default ctor
    Student() = default;

    // Param. ctor
    Student(const char* _name, unsigned _fn, Major _major)
    {
        strcpy(name, _name); // Copy the name safely
        fn = _fn;
        major = _major;
    }
};

void printStudent(const Student& st)
{
    std::cout << st.name << ", fn: " << st.fn << ", major: " << getMajorStr(st.major) << std::endl;
}

struct StudentDatabase
{
    unsigned studentsCount;
    Student students[STUDENT_MAX_SIZE];
};

// void sortStudents(StudentDatabase& database)
// {
//     assert(database.studentsCount <= STUDENTS_MAX_SIZE);
// }

void printDatabase(const StudentDatabase& sdb)
{
    assert(sdb.studentsCount <= STUDENT_MAX_SIZE);

    for (size_t i = 0; i < sdb.studentsCount; ++i)
    {
        printStudent(sdb.students[i]);
    }
}

enum class Criteria
{
    sortByName, sortByFn, sortByMajor
};

void sortDatabase(StudentDatabase& sdb, bool (*isLess) (const Student& lhs, const Student&rhs))
{
    for (int i = 0; i < sdb.studentsCount - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < sdb.studentsCount; j++)
        {
            if (isLess(sdb.students[j], sdb.students[minIndex]))
                minIndex = j;
        }
        if (i != minIndex)
            std::swap(sdb.students[i], sdb.students[minIndex]);
    }
}

void sortByCriteria(StudentDatabase& sdb, Criteria cr)
{
    switch(cr)
    {
        case Criteria::sortByName : return 
                                    sortDatabase(sdb, [](const Student& lhs, const Student& rhs) 
                                                        {return strcmp(lhs.name, rhs.name) < 0;});
        case Criteria::sortByFn : return 
                                    sortDatabase(sdb, [](const Student& lhs, const Student& rhs) 
                                                         {return lhs.fn < rhs.fn;});  
        case Criteria::sortByMajor : return 
                                    sortDatabase(sdb, [](const Student& lhs, const Student& rhs) 
                                                         {return lhs.major > rhs.major;});  
        default: assert(false && "Invalid sorting criteria!"); 
    }
}

int main()
{
    StudentDatabase s =
    {
        3,
        {
            {"Petur", 12, Major::InfS},
            {"Ivan", 12345, Major::Cs},
            {"Aleksandur", 56, Major::S}
        }
    };

    printDatabase(s);
    std::cout << std::endl;

    sortByCriteria(s, Criteria::sortByName);

    printDatabase(s);
    std::cout << std::endl;

    sortByCriteria(s, Criteria::sortByMajor);

    printDatabase(s);
    std::cout << std::endl;

    sortByCriteria(s, Criteria::sortByFn);

    printDatabase(s);
    std::cout << std::endl;

    return 0;
}