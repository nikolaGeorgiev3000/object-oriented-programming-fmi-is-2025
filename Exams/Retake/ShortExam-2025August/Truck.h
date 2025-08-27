#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    // Big Four
    Truck(const char* brand, const char* model, const char* color, 
    double load, const char* loadDescription);
    Truck(const Truck& other);
    Truck& operator=(const Truck& other);
    ~Truck() override;

    void print() const override;
    Truck* clone() const override;
    double calculateTax() const override;

    // Getters
    double getLoad() const;
    const char* getLoadDescription() const;

protected:
    // Setters
    void setLoad(double newLoad);
    void setLoadDescription(const char* newLoadDescription);

private:
    double load;
    char* loadDescription;

    // Helper methods
    void free();
    void copyFrom(const Truck& other);
};

#endif // TRUCK_H