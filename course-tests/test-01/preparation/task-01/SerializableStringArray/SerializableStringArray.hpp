#ifndef _SER_STRING_ARRAY_HPP_
#define _SER_STRING_ARRAY_HPP_

#include <cstring>

class SerializableStringArray
{
  public:
    SerializableStringArray(size_t maxStringCount, size_t maxStringLength);
    SerializableStringArray(const char* filename); // Deserialize

    SerializableStringArray(const SerializableStringArray& other);
    SerializableStringArray& operator=(const SerializableStringArray& other);

    ~SerializableStringArray();

    void addString(const char* str);
    const char* get(unsigned index) const;

    size_t getSize() const;
    size_t getCapacity() const;
    bool isFull() const;

    void writeToBinary(const char* filename) const;

  private:
    char* data = nullptr;

    struct MetaData
    {
        size_t _maxStringCount = 0;
        size_t _maxStringLength = 0;
        size_t _currentCount = 0;
        size_t getAllocationSize() const;
    } _metaData;

    void freeDynamic();
    void copyFromDynamic(const SerializableStringArray& other);
};

#endif