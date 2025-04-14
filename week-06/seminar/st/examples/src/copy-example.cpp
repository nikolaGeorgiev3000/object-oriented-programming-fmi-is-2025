#include <iostream>

class Entity
{
private:
	int x;
public:
	Entity(int x) : x(x) {}

	int get() const
	{
		return x;
	}
};

Entity copy(Entity e)
{
    return e;
}

int main()
{
	Entity e(12);
	std::cout << e.get() << std::endl;
	Entity e_copied = copy(e);
    std::cout << e_copied.get() << std::endl;
}