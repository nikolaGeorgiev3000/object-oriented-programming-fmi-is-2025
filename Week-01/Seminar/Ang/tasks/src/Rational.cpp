#include <assert.h>
#include <iostream>

struct Rational
{
    int nom, denom;
};

bool isValidRat(const Rational& r)
{
    return (r.denom != 0);
}

void printRat(const Rational& r)
{
    std::cout << r.nom << " / " << r.denom << std::endl;
}

unsigned getGcd(unsigned a, unsigned b)
{
    if (b > a)
    {
        std::swap(a, b);
    }

    while (b != 0)
    {
        unsigned temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

void rationalize(Rational& r)
{
    assert(isValidRat(r)); // Signal an error

    unsigned gcd = getGcd(r.nom, r.denom);
    r.nom /= gcd;
    r.denom /= gcd;

    if ((r.nom < 0 && r.denom < 0) || (r.nom > 0 && r.denom < 0))
    {
        r.nom *= -1;
        r.denom *= -1;
    }
}

Rational& plusEquals(Rational& lhs, const Rational& rhs)
{
    assert(isValidRat(lhs) && isValidRat(rhs)); // Assert that they are both valid

    lhs.nom *= rhs.denom;
    lhs.nom += rhs.nom * lhs.denom;
    lhs.denom *= rhs.denom;

    rationalize(lhs);

    return lhs;
}

Rational plusRationals(const Rational& lhs, const Rational& rhs)
{
    assert(isValidRat(lhs) && isValidRat(rhs)); // Assert that they are both valid
    Rational toReturn = lhs;
    plusEquals(toReturn, rhs);

    return toReturn;
}

int main()
{
    Rational r1{1, 5};
    Rational r2{1, 6};

    Rational r3 = plusRationals(r1, r2);

    printRat(r3);

    plusEquals(r3, r2); // == 11 / 30

    printRat(r3); // == 8 / 15

    return 0;
}