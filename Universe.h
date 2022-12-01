#pragma once
#include <time.h>
#include <cmath>

class Universe
{
public:

    int day;
    clock_t tStart;
    double elapsedTime;
    Universe() : day(0)
    {
        tStart = clock();
    }
};
