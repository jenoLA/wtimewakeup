#include <stdio.h>
#include <stdlib.h>
#include "sleepcycle.h"

void helpMessage()
{
    printf("\nusage: wtimewakeup <option> HH:MM\n\n example:\n\twtimewakeup -w 7:20\n\twtimewakeup -s 23:20\n\nnotice that the time format is 24h\n\n");
    exit(1);
}

int main(int argc, char const *argv[])
{
    if (argc == 3)
    {
        if(argv[1][0] == '-')
        {
            int time[4][2];
            int HH, MM;
            
            sscanf(argv[2], "%i:%i", &HH, &MM);

            if(HH > 24 || HH < 0 || MM > 59 || MM < 0)
                helpMessage();
            
            else if (argv[1][1] == 's')
                timeToWakeUp(time, HH, MM);

            else if (argv[1][1] == 'w')
                timeToFallAsleep(time, HH, MM);
            
            // times of the cycle
            char* cycles[] = {"three", "four", "five", "six"};
            float hours[] = {4.30, 6, 7.30, 9};
            
            for (int i = 0; i < 4; ++i)
                printf("\n%s cycles: %i:%i (%0.2f Hours) \n", cycles[i], time[i][0], time[i][1], hours[i]);
        
            printf("\n");
            exit(0);
        }
    }
    
    helpMessage();
}
