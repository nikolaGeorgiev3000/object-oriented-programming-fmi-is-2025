// Напишете програма, която работи с файл с числа, които са кодове на цветове. 
// Числата във файла са разеделени с | (пр. 12465237|12465480|13465277|43243243) 
// и коректността на формата е гарантирана.
#include <fstream>

const char COLOR_DELIMITER = '|';

struct Color
{
    unsigned R:8;
    unsigned G:8;
    unsigned B:8;
};

unsigned getRgbValue(const Color&);
void setColor(Color&, unsigned long);

size_t getColorCount(std::ifstream&);

void readColor(std::ifstream&, Color&);
Color* readColors(std::ifstream&, size_t&);
Color* readColors(const char*, size_t&);

void writeColor(std::ofstream&, const Color&);
void writeColors(std::ofstream&, size_t, const Color*);
void writeColors(const char*, size_t, const Color*);