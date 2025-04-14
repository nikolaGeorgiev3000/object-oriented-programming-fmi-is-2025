#include <iostream>
#include <fstream>

int main()
{
    // constexpr size_t BUFF_SIZE = 10;
    // char buff[BUFF_SIZE] = {};

    // std::cin.getline(buff, BUFF_SIZE * 10, 'a');

    // std::cout << buff << std::endl;

    int x = 0;
    std::cin >> x; // 5
    std::cout << (std::cin.good()) << std::endl; // True -> all is good

    std::cin >> x; // a 
    std::cout << (std::cin.bad()) << std::endl; // False -> no critical error
    std::cout << (std::cin.fail()) << std::endl; // True -> there is an error (not fatal, but still an error)

    std::cout << (std::cin.eof()) << std::endl; // False 

    std::cin.clear(); 

    return 0;
}