#include "mysqrt.h"
#include <math.h>
#include <stdio.h>

double mysqrt(double n) {
    const double epsilon = 1e-6;
    double r = n;
    int i = 0;
    
    while (fabs(r*r - n) > epsilon) {
        i++;  // DEBUG should delete
        r = (r + n/r)/2.0;
    }
        
    printf("%d\n", i);  // DEBUG - should delete
    return r;
}
