#include <iostream>

class Entity {
public:
    Entity() : _x(0) {
        std::cout << "Default c-tor called!\n";
    }

    ~Entity() {
        std::cout << "D-tor called!\n"; 
    }

    void set(int argx) {
        if (argx >= 3) {
            _x = argx;
        }
    }

    int get() const {
        return _x;
    }
private:
    int _x;
};

void drawLine() {
    std::cout << "=========================\n";
}

int main() {
    Entity e;
    drawLine();

    // std::cout << e._x << std::endl; // Inaccessible!

    std::cout << e.get() << std::endl;
    drawLine();
} // D-tor called