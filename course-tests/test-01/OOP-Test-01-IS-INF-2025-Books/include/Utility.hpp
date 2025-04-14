#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

// Important constants for our task
namespace Constants
{
constexpr size_t ID_LEN = 12; // "IS-INF-0000" + '\0'
constexpr size_t INITIAL_CAPACITY = 16;
constexpr size_t MAX_BOOKS = 500;
} // namespace Constants

// Usually used powerful utility-functions
namespace Utils
{
inline bool isValidString(const char* str)
{
    return str && str[0] != '\0'; // Valid when not nullptr, nor empty.
}

inline void safeCopy(char* dest, const char* src, size_t maxLen)
{
    if (!dest || !src || maxLen == 0)
        return;
    size_t i = 0;
    for (; i < maxLen - 1 && src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

// Template function for resizing any type of array.
template <typename T>
inline void resizePointerArray(T*& array, size_t& currentCapacity)
{
    size_t newCapacity = (currentCapacity == 0) ? INITIAL_CAPACITY : currentCapacity * 2;
    T* newArray = new T[newCapacity];

    for (size_t i = 0; i < currentCapacity; ++i)
        newArray[i] = array[i];

    delete[] array;
    array = newArray;
    currentCapacity = newCapacity;
}

// Template function for resizing any type of array of pointers
template <typename T>
inline void resizePointerArray(T**& array, size_t& currentCapacity)
{
    size_t newCapacity = (currentCapacity == 0) ? 2 : currentCapacity * 2;
    T** newArray = new T*[newCapacity];

    for (size_t i = 0; i < currentCapacity; ++i)
        newArray[i] = array[i];

    delete[] array;
    array = newArray;
    currentCapacity = newCapacity;
}

inline char* readDynamicString(std::istream& is, char delimiter = ';')
{
    size_t capacity = Constants::INITIAL_CAPACITY;
    size_t length = 0;
    char* buffer = new char[capacity];

    char ch;
    while (is.get(ch))
    {
        if (ch == delimiter || ch == '\n')
            break;

        if (length + 1 >= capacity)
        {
            Utils::resizePointerArray(buffer, capacity);
        }
        buffer[length++] = ch;
    }
    buffer[length] = '\0';

    return buffer;
}

template <typename T>
inline void shiftLeftFromIndex(T**& array, size_t& count, size_t index)
{
    for (size_t j = index; j < count - 1; ++j)
    {
        array[j] = array[j + 1];
    }
    --count;
    array[count] = nullptr;
}
} // namespace Utils

#endif