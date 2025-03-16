#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ifs("thoreau01.txt");
	if (!ifs.is_open())
	{
		return -1;
	}

	constexpr size_t BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE]{ 0 };

	ifs >> buffer;
	std::cout << buffer << std::endl;

	for (size_t i = 0; i < BUFFER_SIZE; i++)
	{
		buffer[i] = 0;
	}

    // ifs >> std::ws; // Remove the whitespace from the stream
	ifs.getline(buffer, BUFFER_SIZE); // Successfully read the next line
	std::cout << buffer << std::endl;

    // Output: The\n\n
    return 0;
}