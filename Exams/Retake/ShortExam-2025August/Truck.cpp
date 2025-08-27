#include "Truck.h"

Truck::Truck(const char* brand, const char* model, const char* color, 
      double load, const char* loadDescription)
: Vehicle(brand, model, color)
{
    setLoad(load);
    setLoadDescription(loadDescription);
    this->vehicleTax = calculateTax();
}
Truck::Truck(const Truck& other)
: Vehicle(other)
{
    setLoad(other.load);
    setLoadDescription(other.loadDescription);
}
Truck& Truck::operator=(const Truck& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Truck::~Truck() 
{
    free();
}

// Helper methods
void Truck::free()
{
    delete[] loadDescription;
    loadDescription = nullptr;
}

void Truck::copyFrom(const Truck& other)
{
    setLoad(other.load);
    setLoadDescription(other.loadDescription);
}

// Getters
double Truck::getLoad() const
{
    return this->load;
}

const char* Truck::getLoadDescription() const
{
    return this->loadDescription;
}

// Setters
void Truck::setLoad(double newLoad)
{
    if (newLoad <= 0.0)
    {
        throw std::invalid_argument("Invalid new load");
    }
    load = newLoad;
}

void Truck::setLoadDescription(const char* newLoadDescription)
{
    if (!newLoadDescription)
    {
        throw std::invalid_argument("Invalid load description");
    }
    loadDescription = new char[strlen(newLoadDescription) + 1];
    strcpy(loadDescription, newLoadDescription);
}

// Public funct
void Truck::print() const 
{
    std::cout << "Truck: " 
    << this->getBrand() << ", "
    << this->getModel() << ", "
    << this->getColor() << ", "
    << this->getVehicleTax() << ", "
    << load << ", with load description: "
    << loadDescription
    << std::endl;
}

Truck* Truck::clone() const 
{
    return new Truck(*this);
}

double Truck::calculateTax() const 
{
    return 50.0 * this->load;
}