#include "sleepcycle.h"
#include <stdio.h>

int timeToWakeUp(int (*array)[2], char const* time)
{
    int HH, MM;
    sscanf(time, "%i:%i", &HH, &MM);

    if(HH > 24 || HH < 0)
        return 0;

    if(MM > 59 || MM < 0)
        return 0;
    
    HH += 3; //for the second cycle, also notice the on cycle means 1:30 hours

    for (int i = 0; i < 4; ++i)
    {
        HH += 1; //one hour
        MM += 30; // thirty minutes

        if (MM > 59)
        {
            MM -= 60;
            HH += 1;
        }

        if (HH > 23)
            HH -= 24;

        array[i][0] = HH;
        array[i][1] = MM;
    }
    
    return 1;
}

int timeToFallAsleep(int (*array)[2], char const* time)
{
    int HH, MM;
    sscanf(time, "%i:%i", &HH, &MM);

    if(HH > 24 || HH < 0)
        return 0;
    
    else if (MM > 59 || MM < 0)
        return 0;

    HH -= 3; //for the second cycle, also notice the on cycle means 1:30 hours

    for (int i = 0; i < 4; ++i)
    {
        HH -= 1; //one hour
        MM -= 30; // thirty minutes

        if (MM < 0)
        {
            MM += 60;
            HH -= 1;
        }

        if (HH < 0)
            HH += 24;

        array[i][0] = HH;
        array[i][1] = MM;
    }
    return 1;
}
