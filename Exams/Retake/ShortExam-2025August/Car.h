#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

enum class EngineType
{
    Gasoline,
    Diesel,
    Hybrid,
    Electric
};

std::ostream& operator<<(std::ostream& os, EngineType engine);

class Car : public Vehicle
{
public:
    // Big Four
    Car(const char* brand, const char* model, const char* color, EngineType engine, unsigned horsePower);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car() override = default;

    void print() const override;
    Car* clone() const override;
    double calculateTax() const override;
    
    // Getters
    const EngineType getEngine() const;
    unsigned getHorsePower() const;

protected:
    // Setters
    void setEngine(const EngineType& newEngine);
    void setHorsePower(unsigned newHorsePower);

private:
    EngineType engine;
    unsigned horsePower;
};

#endif // CAR_H