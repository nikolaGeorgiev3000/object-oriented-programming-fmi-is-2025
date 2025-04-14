#include <iostream>


struct Vector3D
{
    double x, y, z;

    double getVectorLength()
    {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    Vector3D plus(const Vector3D& other) const // Does not modify `this` object
    {
        Vector3D toReturn;
        toReturn.x = this->x + other.x;
        toReturn.y = this->y + other.y;
        toReturn.z = this->z + other.z;

        return toReturn;
    }

    void print() const
    {
        std::cout << x << ", " << y << ", " << z << ";" << std::endl;
    }
};

double getScalarProduct(const Vector3D& first, const Vector3D& second)
{
    return (first.x * second.x + first.y * second.y + first.z * second.z);
}

bool arePerp(const Vector3D& first, const Vector3D& second)
{
    return getScalarProduct(first, second) == 0;
}

int main()
{
    Vector3D a{ 1, 7, 5 }, b{ -12, 1, 1 };

	std::cout << b.getVectorLength() << std::endl;

	std::cout << getScalarProduct(a, b) << std::endl;
	std::cout << std::boolalpha<< arePerp(a, b) << std::endl;

	//Vector3D c( a.plus(b) );

	Vector3D c;
	c = a.plus(b);
	c.print();

	// това също работи: a.plus(b).print();
	std::cout << std::endl;

	const Vector3D u{ 5,6,7 };
	u.print();

    return 0;
}