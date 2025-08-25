#include "Telephone.h"

Telephone::Telephone(const char* model, const char* brand, double price) 
{
    setModel(model);
    setBrand(brand);
    setPrice(price);
}

Telephone::Telephone(const Telephone& other) 
{
    copyFrom(other);
}

Telephone& Telephone::operator=(const Telephone& other) 
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Telephone::~Telephone()
{
    free();
}

// Helper Methods
void Telephone::free()
{
    delete[] model;
    delete[] brand;
}

void Telephone::copyFrom(const Telephone& other)
{
    setModel(other.model);
    setBrand(other.brand);
    setPrice(other.price);
}

// Getters
const char* Telephone::getBrand() const 
{
    return this->brand;
}

const char* Telephone::getModel() const 
{
    return this->model;
}

double Telephone::getPrice() const 
{
    return this->price;
}

// Setters
void Telephone::setModel(const char* newModel)
{
    try 
    {
        model = new char[strlen(newModel) + 1];
        strcpy(model, newModel);
    } catch (std::exception& e)
    {
        std::cout << "Error with model: " << e.what() << std::endl;
    }
}

void Telephone::setBrand(const char* newBrand)
{
    try 
    {
        brand = new char[strlen(newBrand) + 1];
        strcpy(brand, newBrand);
    } catch (std::exception& e)
    {
        std::cout << "Error with brand: " << e.what() << std::endl;
    }
}
    
void Telephone::setPrice(double newPrice)
{
    if (newPrice <= 0.0)
    {
        throw std::invalid_argument("Wrong price");
    }
    price = newPrice;
}

void Telephone::print() const
{
    std::cout << "Telephone: " << model << ", " << brand << ", " << price << std::endl;
}

// Clone funct
Telephone* Telephone::clone() const
{
    return new Telephone(*this);
}