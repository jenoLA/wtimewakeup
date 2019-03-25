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
            if (argv[1][1] == 's')
                timeToWakeUp(time, argv[2]);

            else if (argv[1][1] == 'w')
                timeToFallAsleep(time, argv[2]);
            
            else
            {
                printf("\nusage: wtimewakeup <option> HH:MM\n\n  example:\n\twtimewakeup -w 7:20\n\twtimewakeup -s 23:20\n\n  notice that the time format is 24h\n");
                exit(1);
            }
            // times of the cycle
            char* cycles[] = {"three", "four", "five", "six"};

            printf("\n");
            for (int i = 0; i < 4; ++i)
                printf("%s cycles: %i:%i H \n\n", cycles[i], time[i][0], time[i][1]);
            
            exit(0);
        }
    }
    
    else
    {
		printf("\nusage: wtimewakeup <option> HH:MM\n\n example:\n\twtimewakeup -w 7:20\n\twtimewakeup -s 23:20\n\nnotice that the time format is 24h\n\n");
		exit(1);
	}
}
