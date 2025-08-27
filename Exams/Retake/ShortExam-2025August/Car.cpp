#include "Car.h"

std::ostream& operator<<(std::ostream& os, EngineType e)
{
    switch (e)
    {
        case EngineType::Gasoline: return os << "Gasoline";
        case EngineType::Diesel:   return os << "Diesel";
        case EngineType::Hybrid:   return os << "Hybrid";
        case EngineType::Electric: return os << "Electric";
    }
    return os << "Unknown";
} 

Car::Car(const char* brand,const char* model, 
         const char* color, EngineType engine, 
         unsigned horsePower)
: Vehicle(brand, model, color), engine(engine) , horsePower(horsePower)
{
    this->vehicleTax = calculateTax();
}

Car::Car(const Car& other)
: Vehicle(other), engine(other.engine), horsePower(other.horsePower)
{}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
        engine = other.engine;
        horsePower = other.horsePower;
    }
    return *this;
}

// Public funct
void Car::print() const
{
    std::cout << "Car: " 
    << this->getBrand() << ", "
    << this->getModel() << ", "
    << this->getColor() << ", "
    << this->getVehicleTax() << ", "
    << engine << ", "
    << horsePower
    << std::endl;
}

Car* Car::clone() const
{
    return new Car(*this);
}

double Car::calculateTax() const
{
    return 10.0 * horsePower; 
}

// Getters
const EngineType Car::getEngine() const
{
    return this->engine;
}

unsigned Car::getHorsePower() const
{
    return this->horsePower;
}

// Setters
void Car::setEngine(const EngineType& newEngine)
{
    engine = newEngine;
}

void Car::setHorsePower(unsigned newHorsePower)
{
    horsePower = newHorsePower;
}
