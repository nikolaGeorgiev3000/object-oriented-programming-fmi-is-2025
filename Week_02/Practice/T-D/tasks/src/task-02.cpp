#include <iostream>

struct ComplexNumber
{
    double real;
    double imag;

    ComplexNumber conjugate() const
    {
        return {real, -imag};
    }

    ComplexNumber operator+(const ComplexNumber& other) const
    {
        return {real + other.real, imag + other.imag};
    }

    ComplexNumber operator-(const ComplexNumber& other) const
    {
        return {real - other.real, imag - other.imag};
    }

    ComplexNumber operator*(const ComplexNumber& other) const
    {
        return {real * other.real - imag * other.imag,
                imag * other.real + real * other.imag};
    }

    ComplexNumber operator/(const ComplexNumber& other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;

        if (denominator == 0)
        {
            std::runtime_error("Division by zero");
        }

        return {
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator};
    }

    bool operator==(const ComplexNumber& other) const
    {
        return (real == other.real && imag == other.imag);
    }

    void print() const
    {
        if (imag < 0)
        {
            std::cout << this->real << " - " << -this->imag << "i" << std::endl;
            return;
        }
        std::cout << this->real << " + " << this->imag << "i" << std::endl;
    }
};

int main()
{
    ComplexNumber c1{3, 5};
    ComplexNumber c2{2, -5};
    ComplexNumber c3{c1};

    std::cout << "Complex numbers:\n";
    c1.print();
    c2.print();

    std::cout << "\nConjugates:\n";
    c1.conjugate().print();
    c2.conjugate().print();

    std::cout << "\nAddition:\n";
    (c1 + c2).print();

    std::cout << "\nSubtraction:\n";
    (c1 - c2).print();

    std::cout << "\nMultiplication:\n";
    (c1 * c2).print();

    std::cout << "\nDivision:\n";

    // Exception handling when division by zero
    try
    {
        (c1 / c2).print();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nEquality checks:\n";
    std::cout << (c1 == c2 ? "Equal" : "Not equal") << std::endl;

    std::cout << (c1 == c3 ? "Equal" : "Not equal") << std::endl;

    return 0;
}