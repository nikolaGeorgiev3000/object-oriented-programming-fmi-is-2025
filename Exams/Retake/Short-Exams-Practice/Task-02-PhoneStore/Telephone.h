/* 
Да се реализира клас Телефон, който описва мобилен телефон със следните характеристики:
* модел, символен низ с произволна дължина;
* марка, символен низ с произволна дължина;
* цена, положително дробно число.
*/

#ifndef TELEPHONE_H
#define TELEPHONE_H

#include <iostream>
#include <cstring>

class Telephone {
public:
    Telephone(const char* newModel, const char* newBrand, double newPrice);
    Telephone(const Telephone& other);
    Telephone& operator=(const Telephone& other);
    virtual ~Telephone();

    // Getters
    const char* getModel() const;
    const char* getBrand() const;
    double getPrice() const;

    // Public Functionality
    virtual void print(std::ostream& ofs) const;

    // Clone Functon
    virtual Telephone* clone() const;

protected:
    // Setters
    void setModel(const char* newModel);
    void setBrand(const char* newBrand);
    void setPrice(double newPrice);

private:
    char* model;
    char* brand;
    double price;

    // Helper Methods
    void free();
    void copyFrom(const Telephone& other);
};

#endif // TELEPHONE_H