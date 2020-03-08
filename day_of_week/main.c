#include <stdio.h>
#include <stdlib.h>

extern int weekday(int day, int month, int year);

int main(int argc, char **argv) {
    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                    "Friday", "Saturday", "Sunday" };

    int wd = weekday(day, month, year);
    printf("%s\n", days[wd-1]);
}
