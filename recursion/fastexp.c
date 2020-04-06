#include <stdio.h>
#include <stdlib.h>
#include "exp.h"

// command line arguments
int main(int argc, char **argv) {
 
    // argc argument count
    // argv is an array of strings
    if (argc > 2) {
        printf("%d\n", slowpow(atoi(argv[1]), atoi(argv[2])));
    }
    return 0;
} 
