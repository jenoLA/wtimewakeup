#include "sleepcycle.h"

void timeToWakeUp(int (*array)[2], int HH, int MM)
{
    HH += 3; //for the second cycle, also notice that one cycle means 1:30 hours

    for (int i = 0; i < 4; ++i)
    {
        HH += 1; //plus one hour
        MM += 30; //plus thirty minutes

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
}

void timeToFallAsleep(int (*array)[2], int HH, int MM)
{
    HH -= 3; //for the second cycle, also notice that one cycle means 1:30 hours

    for (int i = 0; i < 4; ++i)
    {
        HH -= 1; //plus one hour
        MM -= 30; //plus thirty minutes

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
}
