#include <math.h>
#include <stdio.h>

/*
 *  Assume we have a 6GiB data plan, a 64kbps stream,
 *  how many seconds and hours until we have exceeded 
  * the data plan.
 */

int main() {
     
    const double bits = 6*pow(2,30)*8;
    const double bandwidth = 64e3;
    const double time = bits/bandwidth;

    printf("%.2f seconds\n%.2f hours\n", time, time/3600);
}