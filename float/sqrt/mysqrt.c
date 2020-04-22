#include "mysqrt.h"
#include <math.h>

double mysqrt(double n) {
    const double epsilon = 1e-6;
    double r = n;
    
    while (fabs(r*r - n) > epsilon)
        r = (r + n/r)/2.0;
        
    return r;
}
