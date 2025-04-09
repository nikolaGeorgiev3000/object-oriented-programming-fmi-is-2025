#include <iostream>

struct BitFieldExample {
    unsigned b : 3;
};

int main() {
    BitFieldExample bf {6};

    std::cout << ++bf.b << " " << ++bf.b << " " << ++bf.b << std::endl; // 7, then hops over -> 0, then 1;
}