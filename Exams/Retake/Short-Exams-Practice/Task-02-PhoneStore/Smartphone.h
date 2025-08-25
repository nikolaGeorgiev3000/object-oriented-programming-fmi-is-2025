/*
Да се реализира клас Смартфон, които е вид Телефон, с допълнителни характеристики:
* операционна система, символен низ с произволна дължина;
* памет в GB, неотрицателно цяло число;
* цената им се определя като към основната цена се добави лев за всеки GB от паметта.
*/
#pragma once
#include "Telephone.h"

class Smartphone : public Telephone {
public:
    Smartphone(const char* os, unsigned memory, const char* newModel, const char* newBrand, double newPrice);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    ~Smartphone() override;

    // Getters
    const char* getOs() const;
    unsigned getMemory() const;

    // Other Public Functionality
    void print(std::ostream& os) const override;

    // Clone Function
    Smartphone* clone() const override;

protected:
    // Setters
    void setOs(const char* newOs);
    void setMemory(unsigned newMemory);

private:
    char* os;
    unsigned memory;
};