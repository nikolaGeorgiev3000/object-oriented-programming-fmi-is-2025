#include "Telephone.h"

// Helper Methods
void Telephone::free() {
    delete[] model;
    delete[] brand;
}

void Telephone::copyFrom(const Telephone& other) {
    setModel(other.model);
    setBrand(other.brand);
    setPrice(other.price);
}

// Big Four
Telephone::Telephone(const char* newModel, const char* newBrand, double newPrice) {
    try {
        setModel(newModel);
        setBrand(newBrand);
        setPrice(newPrice);
    } catch (std::exception& e) {
        std::cout << "Error setting values: " << e.what() << std::endl;
    }
}

Telephone::Telephone(const Telephone& other) {
    copyFrom(other); 
}

Telephone& Telephone::operator=(const Telephone& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Telephone::~Telephone() {
    free();
}

// Getters
const char* Telephone::getModel() const {
    return this->model;
}

const char* Telephone::getBrand() const {
    return this->brand;
}

double Telephone::getPrice() const {
    return this->price;
}

// Other Public Functionality
void Telephone::print(std::ostream& ofs) const {
    ofs << "Telephone: " << model << ", " << brand << ", " << price << std::endl;
}

// Setters
void Telephone::setModel(const char* newModel) {
    if (!newModel) {
        throw std::invalid_argument("Model cannot be null");
    }

    model = new char[strlen(newModel) + 1];
    strcpy(model, newModel);
}

void Telephone::setBrand(const char* newBrand) {
    if (!newBrand) {
        throw std::invalid_argument("Brand cannot be null");
    }

    brand = new char[strlen(newBrand) + 1];
    strcpy(brand, newBrand);
}

void Telephone::setPrice(double newPrice) {
    if (newPrice <= 0.0) {
        throw std::invalid_argument("Price must be positive");
    }

    price = newPrice;
}

// Clone Function
Telephone* Telephone::clone() const {
    return new Telephone(*this);
}