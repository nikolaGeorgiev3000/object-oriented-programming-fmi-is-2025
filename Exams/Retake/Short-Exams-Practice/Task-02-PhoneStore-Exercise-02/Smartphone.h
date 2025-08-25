/*
Да се реализира клас Смартфон, които е вид Телефон, с допълнителни характеристики:
* операционна система, символен низ с произволна дължина;
* памет в GB, неотрицателно цяло число;
* цената им се определя като към основната цена се добави лев за всеки GB от паметта.    
*/

#include "Telephone.h"

class Smartphone : public Telephone 
{
public:
    // Big Four
    Smartphone(const char* OS, unsigned memory, const char* model, const char* brand, double price);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    ~Smartphone() override;

    // Public Funct
    void print() const override;

    // Getters
    const char* getOS() const;
    unsigned getMemory() const;

    // Clone funct
    Smartphone* clone() const override;

protected:
    // Setters
    void setOS(const char* newOS);
    void setMemory(unsigned newMemory);

private:
    char* OS;
    unsigned memory;

    // Helper Methods
    void free();
    void copyFrom(const Smartphone& other);
};