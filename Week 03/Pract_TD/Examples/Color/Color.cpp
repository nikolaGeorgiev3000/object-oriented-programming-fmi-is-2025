#include <iostream>

#include "Color.h"
#include "functions.h"

constexpr short RGB_CONSTANT = 256;

unsigned getRgbValue(const Color &color)
{
    return color.R == 0 && color.G == 0 && color.B == 0
               ? 256 * 256 * 256
               : color.R * 256 * 256 + color.G * 256 + color.B;
}

size_t getColorCount(std::ifstream &ifs)
{
    if (!ifs.is_open())
    {
        std::cerr << "Error opening file!";
        return 0;
    }

    return getOccurences(ifs, COLOR_DELIMITER) + 1; // The last color does not have a delimiter
}

void setColor(Color &color, unsigned long rgbValue)
{
    color.R = rgbValue / (RGB_CONSTANT * RGB_CONSTANT);
    rgbValue -= color.R * (RGB_CONSTANT * RGB_CONSTANT);

    color.G = rgbValue / (RGB_CONSTANT);
    rgbValue -= color.G * RGB_CONSTANT;

    color.B = rgbValue;
}

// Reading functions
void readColor(std::ifstream &ifs, Color &color)
{
    unsigned long rgbValue;
    ifs >> rgbValue;
    setColor(color, rgbValue);
}

Color *readColors(std::ifstream &ifs, size_t &size)
{
    size = getColorCount(ifs);

    if (size == 0)
        return nullptr;

    Color *colorArr = new Color[size];

    for (size_t i = 0; i < size; ++i)
    {
        readColor(ifs, colorArr[i]);
        ifs.ignore();
    }

    return colorArr;
}

Color *readColors(const char *fileName, size_t &size)
{
    std::ifstream ifs(fileName);

    if (!ifs.is_open())
    {
        std::cerr << "Error opening file!";
        return nullptr;
    }

    return readColors(ifs, size); // As easy as that :)
}

// Writing functions
void writeColor(std::ofstream& ofs, const Color& color)
{
    ofs << getRgbValue(color);
}

void writeColors(std::ofstream& ofs, size_t size, const Color* colorArr) 
{
    if (!ofs.is_open()) return;

    for (size_t i = 0; i < size - 1; ++i) 
    {
        writeColor(ofs, colorArr[i]);
        ofs << COLOR_DELIMITER;
    }
    writeColor(ofs, colorArr[size - 1]); // We don't write a `delimiter` at the end
}

void writeColors(const char* filename, size_t size, const Color* colorArr)
{
    std::ofstream ofs(filename);

    if (!ofs.is_open()) 
    {
        std::cerr << "Error opening file!";
        return;
    }

    writeColors(ofs, size, colorArr); // Abstraction & Polymorphism
}