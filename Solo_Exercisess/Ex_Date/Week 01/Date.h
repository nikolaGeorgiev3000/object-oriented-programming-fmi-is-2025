#pragma once
#include <cstdint>
#include <iostream>

class Date
{
public:
    Date() = default;
    Date(uint16_t time);
    Date(const Date& date);
    Date(Date&& otherObj) noexcept;
    ~Date();
    
    Date& operator=(const Date& otherObj);
    Date& operator=(Date&& otherObj) noexcept;


private:
    uint16_t time;
    
};