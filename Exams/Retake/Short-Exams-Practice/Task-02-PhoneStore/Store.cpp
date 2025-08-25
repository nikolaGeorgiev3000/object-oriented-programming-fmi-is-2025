#include "Store.h"

Store::Store(const unsigned BUDGET) : count(0), capacity(INIT_CAPACITY), BUDGET(BUDGET), currentSum(0) {
    telephones = new (std::nothrow) Telephone*[capacity];
}

Store::Store(const Store& other) : BUDGET(other.BUDGET) {
    copyFrom(other);
}

Store& Store::operator=(const Store& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Store::~Store() {
    free();
    std::cout << "Store destroyed\n";
}

// Helper Methods
void Store::free() {
    for (size_t i = 0; i < count; ++i)
    {
        delete telephones[i];
    }
    delete[] telephones;
    telephones = nullptr; // Reassurance
}
void Store::copyFrom(const Store& other) {
    if (this->BUDGET != other.BUDGET) {
        throw std::invalid_argument("Store Budgets must match!");
    }

    while (this->capacity < other.capacity) {
        this->resize();
    }

    for (unsigned i = 0; i < other.count; ++i)
    {
        telephones[i] = other.telephones[i]->clone();
        ++count;
    }

    currentSum = other.currentSum;
}
void Store::resize() {
    unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;

    delete[] telephones;
    telephones = new (std::nothrow) Telephone*[newCapacity];
    capacity = newCapacity;
};

// Public Functionality
void Store::print(std::ostream& ofs) const {
    for (size_t i = 0; i < count; ++i)
    {
        telephones[i]->print(ofs);
    }
}

void Store::addTelephone(Telephone* t) {
    if (currentSum + t->getPrice() <= BUDGET) {
        if (count == capacity) {
            resize();
        }

        telephones[count] = t->clone();
        ++count;
        currentSum += t->getPrice();
        std::cout << "Telephone with model " << t->getModel() << " added to the store.\n";
        std::cout << "The current sum of the store is: " << currentSum << "\n\n";
        return;
    } 
    std::cout << "Telephone with model " << t->getModel() << " not added to the store due to budget crisis.\n";
}
    
void Store::removeTelephone(const char* model, const char* brand) {
    for (size_t i = 0; i < count; ++i)
    {
        if (strcmp(telephones[i]->getModel(), model) == 0 && strcmp(telephones[i]->getBrand(), brand) == 0) {
            currentSum -= telephones[i]->getPrice();
            std::cout << "Telephone with model " << telephones[i]->getModel() << " removed from the store.\n";
            std::cout << "The current sum of the store is: " << currentSum << "\n\n";

            for (size_t j = i; j < count - 1; j++)
            {
                telephones[j] = std::move(telephones[j + 1]);
            }

            --count;
            return;
        }
    }
    std::cout << "No such telephone found in the store.\n";
}