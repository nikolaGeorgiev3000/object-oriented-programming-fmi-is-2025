/*
Магазин за мобилни телефони разполага с начален бюджет за снабдяване с телефони. 
Този бюджет се подава при създаване на магазина и не се променя.
В магазина могат да се извършват следните операции:
* Към вече наличните в магазина телефони може да се добавя нов, ако бюджетът няма да бъде надвишен. 
* Може да бъде премахнат телефон от магазина, по подадени модел и марка (продажба). Това действие възстановява сумата в бюджета.
*/

#pragma once

#include "Smartphone.h"

class Store
{
public:
    // Big Four
    Store(const unsigned BUDGET);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store();

    void print() const;
    bool addTelephone(const Telephone* t); // Bool return type in order to signal for operation's success
    bool removeTelephone(const char* model, const char* brand);

private:
    Telephone** tels;
    unsigned capacity;
    unsigned count;
    const unsigned BUDGET;
    double sumPrices;

    // Helper methods
    void free();
    void copyFrom(const Store& other);
    void resize();
};
