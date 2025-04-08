/* 
6. Създайте структура Pair, която представя наредена двойка от естествени числа. 
Създайте структура, която представя релация. 
В релацията има най-много 25 наредени двойки и структурата пази текущия си размер.

Напишете функция, която прочита релация от даден файл.
Напишете функция, която добавя наредена двойка към релацията.
Напишете функция, която записва релацията в даден файл.
*/
#include <iostream> 
#include <fstream>

constexpr size_t MAX_PAIRS = 25;

struct Pair {
    unsigned int first;
    unsigned int second;
};

struct Relation {
    Pair pairs[MAX_PAIRS];
    unsigned int size = 0;
};

bool readRelationFromFile(const char* filename, Relation& relation) {
    if (!filename) return false;

    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file with name: " << filename << "\n";
        return false;
    }

    unsigned int a, b;
    relation.size = 0;

    while (inFile >> a >> b) {
        if (relation.size >= MAX_PAIRS) break; // Exit the `while` loop

        relation.pairs[relation.size].first = a;
        relation.pairs[relation.size].second = b;
        ++relation.size;
    }

    inFile.close();

    return true; // Successful operation!
}

bool addPairToRelation(const Pair& pair, Relation& relation) {
    if (relation.size >= MAX_PAIRS) return false; // Cannot add any more pairs to the relation

    relation.pairs[relation.size].first = pair.first;
    relation.pairs[relation.size].second = pair.second;
    ++relation.size;

    return true;
}

bool writeRelationToFile(const char* filename, const Relation& relation) {
    if (!filename) return false;

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file with name: " << filename << "\n";
        return false;
    }

    for (size_t i = 0; i < relation.size; ++i)
    {
        outFile << relation.pairs[i].first 
                << ' '
                << relation.pairs[i].second
                << '\n';
    }

    outFile.close();

    return true;
}

int main() {
    Relation rel;
    Pair pair1 {10, 20};
    Pair pair2 {30, 40};

    if (!readRelationFromFile("task06_inputFile.txt", rel)) {
        std::cerr << "Неуспешно четене на релация!" << std::endl;
        return 1;
    }

    addPairToRelation(pair1, rel);
    addPairToRelation(pair2, rel);

    if (!writeRelationToFile("task06_outputFile.txt", rel)) {
        std::cerr << "Неуспешно записване на релация!" << std::endl;
        return 1;
    }

    std::cout << "Operation successful!";
    return 0;
}