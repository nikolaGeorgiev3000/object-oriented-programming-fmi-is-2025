#include <iostream>

#include "Time.h"

Time::Time() : Time(0, 0, 0) {}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::Time(unsigned secondsFromMidnight)
{
    initializeFromSeconds(secondsFromMidnight);
}

void Time::setHours(unsigned hours)
{
    if (hours >= 24)
    {
        return;
    }
    hrs = hours;
}

void Time::setMinutes(unsigned minutes)
{
    if (minutes >= 60)
    {
        return;
    }
    mins = minutes;
}

void Time::setSeconds(unsigned seconds)
{
    if (seconds >= 60)
    {
        return;
    }
    sec = seconds;
}

void Time::initializeFromSeconds(unsigned secondsFromMidnight)
{
}