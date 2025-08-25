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

// Public funct
void Telephone::print() const
{
    std::cout << "Telephone: " << brand << ", " << model << ", price: " << price << std::endl;
}

Telephone* Telephone::clone() const
{
    return new Telephone(*this);
}

// Getters
const char* Telephone::getModel() const
{
    return this->model;
}

const char* Telephone::getBrand() const
{
    return this->brand;
}

double Telephone::getPrice() const
{
    return this->price;
}

// Setters
void Telephone::setModel(const char* newModel)
{
    if (!newModel)
    {
        throw std::invalid_argument("Not a valid model to set");
    }
    model = new char[strlen(newModel) + 1];
    strcpy(model, newModel);
}

void Telephone::setBrand(const char* newBrand)
{
    if (!newBrand)
    {
        throw std::invalid_argument("Not a valid brand to set");
    }
    brand = new char[strlen(newBrand) + 1];
    strcpy(brand, newBrand);
}

void Telephone::setPrice(double newPrice)
{
    if (newPrice <= 0.0)
    {
        throw std::invalid_argument("Price must be positive");
    }

    price = newPrice;
}

// Helper methods
void Telephone::free()
{
    delete[] model;
    delete[] brand;
    model = nullptr;
    brand = nullptr;
}

void Telephone::copyFrom(const Telephone& other)
{
    setModel(other.model);
    setBrand(other.brand);
    setPrice(other.price);
}