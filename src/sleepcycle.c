#include "../include/sleepcycle.h"
#include <stdio.h>

void timeToWakeUp(int (*array)[2], char const* time)
{
	int HH, MM;
	sscanf(time, "%i:%i", &HH, &MM);
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
}

void timeToFallAsleep(int (*array)[2], char const* time)
{
	int HH, MM;
	sscanf(time, "%i:%i", &HH, &MM);
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
}