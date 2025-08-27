#ifndef GARAGE_H
#define GARAGE_H

#include "Car.h"
#include "Truck.h"

constexpr unsigned INIT_CAPACITY = 4;

class Garage
{
public:
    // Big Four
    Garage(const unsigned GARAGE_CAPACITY);
    Garage(const Garage& other);
    Garage& operator=(const Garage& other);
    ~Garage();

    // Public funct
    void printGarage() const;
    bool addVehicle(const Vehicle* v);
    bool removeVehicleByModelAndBrand(const char* model, const char* brand);
    double getTotalTax() const;
    Vehicle* operator[](unsigned index) const;

    // Getters
    unsigned getGarageCapacity() const;
    unsigned getVehicleCount() const;

private:
    Vehicle** vehicles;
    unsigned capacity;
    unsigned vehicleCount;
    const unsigned GARAGE_CAPACITY = 4; 

    // Helper methods
    void free();
    void copyFrom(const Garage& other);
    void resize();
    void nullifyRange(unsigned from, unsigned to);

};

#endif // GARAGE_H