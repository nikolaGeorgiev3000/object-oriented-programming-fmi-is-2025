/* 
Магазин за мобилни телефони разполага с начален бюджет за снабдяване с телефони. 
Този бюджет се подава при създаване на магазина и не се променя.
В магазина могат да се извършват следните операции:
    * Към вече наличните в магазина телефони може да се добавя нов, ако бюджетът няма да бъде надвишен. 
    * Може да бъде премахнат телефон от магазина, по подадени модел и марка (продажба). Това действие възстановява сумата в бюджета.
*/

#pragma once

#include "Smartphone.h"

constexpr unsigned INIT_CAPACITY = 16;

class Store {
public:
    // Big Four
    Store(const unsigned BUDGET);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store();

    // Public Functionality
    void print(std::ostream& ofs) const;

    void addTelephone(Telephone* t);
    void removeTelephone(const char* model, const char* brand);

private:
    Telephone** telephones;
    unsigned count;
    unsigned capacity;
    const unsigned BUDGET;

    double currentSum; // Store the current sum of telephone prices

    // Helper Methods
    void free();
    void copyFrom(const Store& other);
    void resize();
};