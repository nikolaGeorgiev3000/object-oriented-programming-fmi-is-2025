#include "SerializableStringArray.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>

#pragma warning(disable : 4996)

// Constructors
SerializableStringArray::SerializableStringArray(size_t maxStringCount, size_t maxStringLength)
    : _metaData{maxStringCount, maxStringLength}
{
    data = new char[_metaData.getAllocationSize()];
}

SerializableStringArray::SerializableStringArray(const char* filename)
{ // Deserialize
    std::ifstream ifs(filename, std::ios::binary);

    if (!ifs.is_open())
    {
        throw std::runtime_error("Error opening file!");
    }

    ifs.read(reinterpret_cast<char*>(&_metaData), sizeof(MetaData));
    size_t newLen = _metaData.getAllocationSize();
    // std::cout << newLen << std::endl;
    data = new char[newLen];
    ifs.read(data, newLen);

    ifs.close();
}

SerializableStringArray::SerializableStringArray(const SerializableStringArray& other)
    : _metaData(other._metaData)
{
    copyFromDynamic(other);
}

// Operators
SerializableStringArray& SerializableStringArray::operator=(const SerializableStringArray& other)
{
    if (this != &other)
    {
        _metaData = other._metaData;
        freeDynamic();
        copyFromDynamic(other);
    }

    return *this;
}

// Destructor
SerializableStringArray::~SerializableStringArray()
{
    freeDynamic();
}

// Functionality
void SerializableStringArray::addString(const char* str)
{
    if (!str)
        throw std::invalid_argument("Inv. string!");
    if (strlen(str) > _metaData._maxStringLength)
        throw std::invalid_argument("Too long string.");
    if (isFull())
        throw std::logic_error("Full collection.");

    size_t indexToAddOn = _metaData._currentCount * (_metaData._maxStringLength + 1);
    strcpy(data + indexToAddOn, str);
    ++_metaData._currentCount;
}

const char* SerializableStringArray::get(unsigned index) const
{
    if (index >= _metaData._currentCount)
        throw std::out_of_range("No such index!");

    size_t beginIndexOfCurrentString = index * (_metaData._maxStringLength + 1);
    return data + beginIndexOfCurrentString;
}

// Getters
size_t SerializableStringArray::getSize() const
{
    return _metaData._currentCount;
}
size_t SerializableStringArray::getCapacity() const
{
    return _metaData._maxStringCount;
}

// Streams
void SerializableStringArray::writeToBinary(const char* filename) const
{
    std::ofstream ofs(filename, std::ios::binary);

    if (!ofs)
    {
        throw std::runtime_error("Error opening file!");
    }

    ofs.write(reinterpret_cast<const char*>(&_metaData), sizeof(MetaData));
    ofs.write(data, _metaData.getAllocationSize());

    ofs.close();
}

// Helpers
bool SerializableStringArray::isFull() const
{
    return getCapacity() == getSize();
}

void SerializableStringArray::freeDynamic()
{
    delete[] data;
    data = nullptr;
}

void SerializableStringArray::copyFromDynamic(const SerializableStringArray& other)
{
    size_t newLen = other._metaData.getAllocationSize();
    data = new char[newLen];

    for (size_t i = 0; i < newLen; ++i)
    {
        data[i] = other.data[i];
    }

    // strncpy(data, other.data, newLen - 1);
    // data[newLen] = '\0';
}