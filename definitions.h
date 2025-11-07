//
// Created by bohan on 2022/9/27.
//

#ifndef QT_MASTER_DEFINITIONS_H
#define QT_MASTER_DEFINITIONS_H

#include "math.h"

#define FREQUENCE 1000

#define NUM_OF_MOTORS 2

inline double switch360(double x)
{
    if(x > 240)
        return x - 360;
    else if(x < -240)
        return x + 360;
    else
        return x;
}

inline double to0_360(double x)
{
    x = fmod(x, 360);
    x = fmod(x + 360, 360);
    return x;
}

#endif //QT_MASTER_DEFINITIONS_H
