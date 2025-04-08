/* 
7. Създайте структура City, която описва град и има име (до 63 символа) и брой жители. 
Създайте и структура District, която съдържа в себе си до 20 града и пази текущия си размер.

Напишете функция, която записва във файл една област.
Напишете друга функция, която прочита област от файл, след което сортира градовете в 
областта според броя на жителите им във възходящ ред и записва резултата в друг файл.
*/
#include <iostream>
#include <fstream>
#include <cstring>

constexpr size_t MAX_CITY_NAME_LEN = 64;
constexpr size_t MAX_CITIES = 20;

struct City {
    char name[MAX_CITY_NAME_LEN];
    unsigned int population;
};

struct District {
    City cities[MAX_CITIES];
    unsigned int size = 0;
};

bool writeDistrictToFile(const char* filename, const District& district) {
    if (!filename) return false;

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file with name: " << filename << "\n";
        return false;
    }

    for (unsigned int i = 0; i < district.size; ++i)
    {
        outFile << district.cities[i].name 
                << ' '
                << district.cities[i].population
                << '\n';
    }
    
    outFile.close();

    return true;
}

void sortDistrictByPopulation (District& district) {
    for (size_t i = 0; i < district.size - 1; ++i)
    {
        for (size_t j = i + 1; j < district.size; ++j)
        {
            if (district.cities[i].population > district.cities[j].population) {
                City temp;

                strcpy(temp.name, district.cities[i].name);
                temp.population = district.cities[i].population;

                strcpy(district.cities[i].name, district.cities[j].name);
                district.cities[i].population = district.cities[j].population;

                strcpy(district.cities[j].name, temp.name);
                district.cities[j].population = temp.population;
            }
        }   
    }
}

bool readAndSortDistrict(const char* inputFilename, const char* outputFilename) {
    if (!inputFilename || !outputFilename) return false;

    std::ifstream inFile(inputFilename);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file with name: " << inputFilename << "\n";
        return false;
    }

    District district;
    district.size = 0;

    while (inFile >> district.cities[district.size].name >> district.cities[district.size].population) {
        ++district.size;
        if (district.size >= MAX_CITIES) break;
    }

    inFile.close(); // Close the input stream

    sortDistrictByPopulation(district); // Sort the district

    return writeDistrictToFile(outputFilename, district);
}

int main() {
    const char* inputFile = "task07_input_district.txt";
    const char* outputFile = "task07_sorted_district.txt";

    if (!readAndSortDistrict(inputFile, outputFile)) {
        std::cerr << "Грешка." << std::endl;
        return 1;
    }

    std::cout << "Сортирането приключи успешно. Резултат в: " << outputFile << std::endl;

    return 0;
}