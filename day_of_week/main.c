#include <stdlib.h>
#include <stdio.h>
#include "dow.h"

/*
 *  What day was Feb 14, 2000 on?
 *
 *  ./day 2 14 2000
 *  Monday
 *
 */
int main(int argc, char **argv) {
    int month = atoi(argv[1]);
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);

    int dow = weekday(month, day, year);
    printf("DEBUG: %d\n", dow);

    char *days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                     "Thursday", "Friday", "Saturday"};

    //printf("%s\n", days[dow]);
}


