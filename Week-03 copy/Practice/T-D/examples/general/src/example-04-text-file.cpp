#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("thoreau02.txt");
    char symbol;
    ifs.seekg(5, std::ios::beg);      // ... m<here>ass of men ...
    symbol = ifs.get();               // gets the char 'a' & moves: ... ma<here>ss of men ...
    std::cout << symbol << std::endl; // a\n
    ifs.seekg(-4, std::ios::cur);     // Th<here>e mass of ...
    symbol = ifs.get();               // gets the char 'e' & moves: The<here> mass of ...
    std::cout << symbol << std::endl; // e\n
    ifs.seekg(-2, std::ios::end);     // ... eratio<here>n.
    symbol = ifs.get();               // gets the char 'n' & moves: ... eration<here>.
    std::cout << symbol << std::endl; // n\n
    ifs.seekg(-1, std::ios::cur);     // ... eratio<here>n.
    symbol = ifs.get();               // gets the char 'n' & moves: ... eration<here>.
    std::cout << symbol << std::endl; // n\n

    // Output: a\ne\nn\nn\n
}