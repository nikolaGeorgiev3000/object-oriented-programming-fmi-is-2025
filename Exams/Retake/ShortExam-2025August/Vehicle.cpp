#include "Vehicle.h"

Vehicle::Vehicle(const char* brand, const char* model, const char* color)
: vehicleTax(0.0)
{
    setBrand(brand);
    setModel(model);
    setColor(color);
}

Vehicle::Vehicle(const Vehicle& other)
: vehicleTax(other.vehicleTax)
{
    copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        free();
        vehicleTax = other.vehicleTax;
        copyFrom(other);
    }
    return *this;
}

Vehicle::~Vehicle()
{
    free();
}

// Public funct

// Getters
const char* Vehicle::getBrand() const
{
    return this->brand;
}
const char* Vehicle::getModel() const
{
    return this->model;
}
const char* Vehicle::getColor() const
{
    return this->color;
}
double Vehicle::getVehicleTax() const
{
    return this->vehicleTax;
}

// Setters
void Vehicle::setBrand(const char* newBrand)
{
    if (!newBrand)
    {
        throw std::invalid_argument("Invalid new brand");
    }
    brand = new char[strlen(newBrand) + 1];
    strcpy(brand, newBrand);
}

void Vehicle::setModel(const char* newModel)
{
    if (!newModel)
    {
        throw std::invalid_argument("Invalid new model");
    }
    model = new char[strlen(newModel) + 1];
    strcpy(model, newModel);
}

void Vehicle::setColor(const char* newColor)
{
    if (!newColor)
    {
        throw std::invalid_argument("Invalid new color");
    }
    color = new char[strlen(newColor) + 1];
    strcpy(color, newColor);
}

// Helper methods
void Vehicle::free()
{
    delete[] brand;
    delete[] model;
    delete[] color;
    brand = model = color = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
    setBrand(other.brand);
    setModel(other.model);
    setColor(other.color);
}