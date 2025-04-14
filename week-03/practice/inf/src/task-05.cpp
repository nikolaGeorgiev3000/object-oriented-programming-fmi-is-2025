/*
Създайте програма, която прочита редовете на файл, чието име се чете от стандартния вход.
Сортирайте лексикографски редовете на файла и ги запишете в друг файл, чието
име също се чете от стандартния вход. Опитайте да решите същата задача, но записването
на редовете да бъде в същия файл.
*/

#include <cstring>
#include <fstream>
#include <iostream>
#pragma warning(disable : 4996)

int getLinesCount(std::ifstream& ifs)
{
    if (ifs.is_open())
    {
        int lines = 0;

        char buffer[256];

        while (ifs.getline(buffer, 256))
        {
            ++lines;
        }

        ifs.clear();
        ifs.seekg(0, std::ios::beg);

        return lines;
    }

    return -1;
}

char** getLines(std::ifstream& ifs, size_t size)
{
    if (ifs.is_open())
    {
        char** lines = new char*[size];

        char buffer[256];

        for (size_t i = 0; ifs.getline(buffer, 256); ++i)
        {
            int len = strlen(buffer);
            lines[i] = new (std::nothrow) char[len + 1];
            strncpy(lines[i], buffer, len);
        }

        ifs.clear();
        ifs.seekg(0, std::ios::beg);

        return lines;
    }

    return nullptr;
}

int partition(char** arr, size_t size)
{
    if (strcmp(arr[size - 1], arr[0]) > 0)
    {
        std::swap(arr[size - 1], arr[0]);
    }

    char*& pivot = arr[size - 1];

    int left = 0, right = size - 1;

    while (true)
    {
        while (strcmp(arr[left], pivot) < 0)
            ++left;

        while (strcmp(arr[right], pivot) > 0)
            --right;

        if (left < right)
        {
            std::swap(arr[left], arr[right]);
        }
        else
        {
            break;
        }
    }

    return left;
}

void quickSort(char** arr, size_t size)
{
    if (!arr || size < 2)
        return;

    int part = partition(arr, size);

    quickSort(arr, part);
    quickSort(arr + part, size - part);
}

int main()
{
    const char fpath[] = "";

    std::ifstream ifs(fpath, std::ios::in);

    int linesCount = getLinesCount(ifs);
    char** lines = getLines(ifs, linesCount);

    ifs.close();

    quickSort(lines, linesCount);

    std::ofstream ofs(fpath, std::ios::out);

    for (size_t i = 0; i < linesCount; ++i)
    {
        ofs << lines[i] << '\n';
        delete[] lines[i];
    }
    delete[] lines;

    ofs.close();

    return 0;
}