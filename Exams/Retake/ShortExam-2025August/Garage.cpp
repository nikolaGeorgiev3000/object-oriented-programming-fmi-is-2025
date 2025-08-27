#include "Garage.h"

Garage::Garage(const unsigned GARAGE_CAPACITY) 
: GARAGE_CAPACITY(GARAGE_CAPACITY), capacity(INIT_CAPACITY),
  vehicleCount(0)  
{
    vehicles = new (std::nothrow) Vehicle*[capacity];
    nullifyRange(0, capacity);  
}

Garage::Garage(const Garage& other)
: GARAGE_CAPACITY(other.GARAGE_CAPACITY), capacity(other.capacity),
  vehicleCount(other.vehicleCount)
{
    copyFrom(other);
}

Garage& Garage::operator=(const Garage& other)
{
    if (this != &other)
    {
        if (this->GARAGE_CAPACITY != other.GARAGE_CAPACITY)
        {
            throw std::invalid_argument("Garage capacities must match when using assignment operator");
        }
        capacity = other.capacity;
        vehicleCount = other.vehicleCount;
        free();
        copyFrom(other);
    }
    return *this;
}

Garage::~Garage()
{
    free();
}

// Helper methods
void Garage::copyFrom(const Garage& other)
{
    vehicles = new (std::nothrow) Vehicle*[other.capacity];
    for (size_t i = 0; i < other.vehicleCount; ++i)
    {
        vehicles[i] = other.vehicles[i]->clone();
    }  
    nullifyRange(other.vehicleCount, other.capacity);
}

void Garage::free()
{
    for (size_t i = 0; i < vehicleCount; ++i)
    {
        delete vehicles[i];
    }
    delete[] vehicles;    
}

void Garage::resize()
{
    capacity *= 2;

    Vehicle** temp = new (std::nothrow) Vehicle*[capacity];
    for (size_t i = 0; i < vehicleCount; ++i)
    {
        temp[i] = vehicles[i];
    }

    delete[] vehicles;
    vehicles = temp;
    nullifyRange(vehicleCount, capacity);
}

void Garage::nullifyRange(unsigned from, unsigned to)
{
    for (unsigned i = from; i < to; ++i)
    {
        vehicles[i] = nullptr;
    }
}

// Getters
unsigned Garage::getGarageCapacity() const
{
    return this->GARAGE_CAPACITY;
}

unsigned Garage::getVehicleCount() const
{
    return this->vehicleCount;
}

// Public functionality

void Garage::printGarage() const
{
    for (size_t i = 0; i < vehicleCount; ++i)
    {
        if (!vehicles[i])
        {
            std::cout << "Null Vehicle\n";
            continue;
        }
        vehicles[i]->print();
    }
    std::cout << std::endl;
}

double Garage::getTotalTax() const
{
    double totalTax = 0.0;
    for (size_t i = 0; i < vehicleCount; ++i)
    {
        totalTax += vehicles[i]->getVehicleTax();
    }
    return totalTax;
}

Vehicle* Garage::operator[](unsigned index) const
{
    // Guard Safety
    if (index >= vehicleCount || !vehicles[index])
    {
        return nullptr;
    }
    return vehicles[index]->clone();
}

bool Garage::addVehicle(const Vehicle* v)
{
    if (!v)
    {
        throw std::invalid_argument("Invalid vehicle to add");
    }
    if (vehicleCount == GARAGE_CAPACITY)
    {
        std::cout << "Maximum Garage Capacity reached.\n";
        return false;
    }
    if (vehicleCount == capacity)
    {
        resize();
    }

    vehicles[vehicleCount] = v->clone();
    ++vehicleCount;
    return true;
}

bool Garage::removeVehicleByModelAndBrand(const char* model, const char* brand)
{
    unsigned checkChangeVehCount = vehicleCount;
    for (size_t i = 0; i < vehicleCount; ++i)
    {
        if (strcmp(vehicles[i]->getModel(), model) == 0 
            && strcmp(vehicles[i]->getBrand(), brand) == 0)
        {
            delete vehicles[i];
            for (size_t j = i; j < vehicleCount - 1; ++j)
            {
                vehicles[j] = vehicles[j + 1];
            }
            --vehicleCount;
            vehicles[vehicleCount] = nullptr;

            --i; // Continues the check from the same position
        }
    }
    if (checkChangeVehCount == vehicleCount)
    {
        std::cout << "No such vehicle found in the garage\n";
        return false;
    }
    return true;
}