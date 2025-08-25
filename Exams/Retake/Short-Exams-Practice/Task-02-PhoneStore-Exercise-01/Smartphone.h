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

    void print(std::ostream& ofs) const override;
    Smartphone* clone() const override;

    // Getters
    const char* getOS() const;
    unsigned getMemory() const;

protected:
    // Setters
    void setOS(const char* newOS);
    void setMemory(unsigned newMemory);

private:
    char* OS;
    unsigned memory;
};