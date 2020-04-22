#include <stdio.h>
#include "f2c.h"
#include <stdlib.h>

int main(int argc, char ** argv) {
    
    printf("%.1f\n", f2c(atof(argv[1])));
    
    return 0;
}
