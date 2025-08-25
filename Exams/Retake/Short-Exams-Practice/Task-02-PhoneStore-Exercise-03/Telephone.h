/*
Да се реализира клас Телефон, който описва мобилен телефон със следните характеристики:
* модел, символен низ с произволна дължина;
* марка, символен низ с произволна дължина;
* цена, положително дробно число.
*/
#pragma once

#include <iostream>
#include <cstring>

class Telephone 
{
public:
    // Big Four
    Telephone(const char* model, const char* brand, double price);
    Telephone(const Telephone& other);
    Telephone& operator=(const Telephone& other);
    virtual ~Telephone();

    virtual void print() const;
    virtual Telephone* clone() const;

    const char* getModel() const;
    const char* getBrand() const;
    double getPrice() const;

protected:
    // Setters
    void setModel(const char* newModel);
    void setBrand(const char* newBrand);
    void setPrice(double newPrice);

private:
    char* model;
    char* brand;
    double price;

    // Helper methods
    void free();
    void copyFrom(const Telephone& other);
};