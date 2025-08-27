// Disclaimer: Completely forgot the third char* member-data of Vehicle, so I used color as a replacement
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>
#include <stdexcept>

// Abstract class
class Vehicle
{
public:
    // Big Four
    Vehicle(const char* brand, const char* model, const char* color);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    virtual ~Vehicle() = 0; // We don't have Vehicle instances

    virtual void print() const = 0;
    virtual Vehicle* clone() const = 0; 
    virtual double calculateTax() const = 0;

    // Getters
    const char* getBrand() const;
    const char* getModel() const;
    const char* getColor() const;
    double getVehicleTax() const;

protected:
    // Setters
    void setBrand(const char* newBrand);
    void setModel(const char* newModel);
    void setColor(const char* newColor);
    // Vehicle tax cannot be set by the user
    double vehicleTax; // Protected, in order to allow access from the successors

private:
    char* brand;
    char* model;
    char* color;
    
    // Helper methods
    void free();
    void copyFrom(const Vehicle& other);
};

#endif // VEHICLE_H