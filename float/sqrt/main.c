#include <stdio.h>
#include <stdlib.h>
#include "mysqrt.h"
#include <math.h>

int main(int argc, char **argv) {
    double n = atof(argv[1]);
    
    printf("%.10f %.10f\n", mysqrt(n), sqrt(n));
}
