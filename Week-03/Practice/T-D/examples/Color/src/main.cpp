#include <iostream>

#include "Color.h"

int main()
{
    size_t size = 0;
    Color* colors = readColors("colors_to_read.txt", size);

    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "(" << colors[i].R << ", " << colors[i].G << ", " << colors[i].B << ")\n";
    }

    // TODO: Reading/writing not correct, somewhere breaks, debug
    writeColors("colors_to_write.txt", size, colors);

    // Free the heap
    delete[] colors;
}