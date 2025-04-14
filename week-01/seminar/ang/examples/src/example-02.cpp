#include <iostream>

struct Box
{
	double height;
	double width;
	double length;
	// double height, width, length; is also possible
};

double calcVolume(const Box& b) // ConstRef because we do not modify the object
{
    return b.height * b.length * b.width;
}

void printBox(const Box& b) // ConstRef because we do not modify the object
{
    std::cout << "(" << b.height << ", " << b.length << ", " << b.width << ") ";
}

void readBox(Box& b)
{
    std::cin >> b.height >> b.length >> b.width;
}
int main()
{
    // Box b1; // default values to height and width and length
    // Box b2{1, 2, 3};
    // Box b3 = {3, 4, 3.4};
    // Box b4;
    // b4.height = 1.2;
    // b4.length = 1.3;
    // b4.width = 1.4;

    // std::cout << "Enter dimensions of your box: \n";
    // readBox(b1);

    // double volumeOfBox = calcVolume(b1);

    // std::cout << "The volume of box ";
    // printBox(b1);
    // std::cout << "is " << volumeOfBox << std::endl;

    Box* boxPtr = new Box();

    boxPtr->height = 1.5;
    boxPtr->width = 2.5;
    boxPtr->length = 3.5;

    printBox(*boxPtr);

    std::cout << "Volume: " << calcVolume(*boxPtr) << std::endl;

    return 0;
}