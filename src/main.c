#include <stdio.h>
#include <stdlib.h>
#include "sleepcycle.h"

int main(int argc, char const *argv[])
{
    if (argc == 3)
    {
        if(argv[1][0] == '-')
        {
            int time[4][2];
            int success;
            
            if (argv[1][1] == 's')
                success = timeToWakeUp(time, argv[2]);

            else if (argv[1][1] == 'w')
                success = timeToFallAsleep(time, argv[2]);
            
            // times of the cycle
            if (success)
            {
                char* cycles[] = {"three", "four", "five", "six"};
                float hours[] = {4.30, 6, 7.30, 9};
                for (int i = 0; i < 4; ++i)
                    printf("\n%s cycles: %i:%i (%0.2f Hours) \n", cycles[i], time[i][0], time[i][1], hours[i]);
            
                printf("\n");
                exit(0);
            }
        }
    }
    
    else
    {
		printf("\nusage: wtimewakeup <option> HH:MM\n\n example:\n\twtimewakeup -w 7:20\n\twtimewakeup -s 23:20\n\nnotice that the time format is 24h\n\n");
		exit(1);
	}
}
