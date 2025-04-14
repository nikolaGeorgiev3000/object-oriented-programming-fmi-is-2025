#include <iostream>

struct BitFieldExample
{
    unsigned b : 3;
};

struct StreamState
{
    unsigned char goodBit : 1;
    unsigned char badBit : 1;
    unsigned char failBit : 1;
    unsigned char eofBit : 1;
};

struct FilePermissions
{
    // owner permissions
    unsigned int owner_read : 1;
    unsigned int owner_write : 1;
    unsigned int owner_execute : 1;

    // group permissions
    unsigned int group_read : 1;
    unsigned int group_write : 1;
    unsigned int group_execute : 1;

    // other permissions
    unsigned int other_read : 1;
    unsigned int other_write : 1;
    unsigned int other_execute : 1;
};

union FlagsByte
{
    struct
    {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    } bits;

    unsigned char raw = 0;
};

int main()
{
    std::cout << sizeof(BitFieldExample) << std::endl; // 4B
    std::cout << sizeof(StreamState) << std::endl;     // 1B
    std::cout << sizeof(FilePermissions) << std::endl; // 4B

    FlagsByte f;

    f.bits.bit0 = 1;
    f.bits.bit3 = 1;

    std::cout << "Байтово представяне: 0x" << std::hex << static_cast<int>(f.raw) << std::endl;
    // Пример: 0x09 (00001001)

    return 0;
}