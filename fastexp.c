#include <stdio.h>
#include <stdlib.h>

int intpow(int x, int y) {
    if (y == 0) 
        return 1;
    else if (y & 1)
        return x * intpow(x, y - 1);
    else {
        int tmp = intpow(x, y >> 1);
        return tmp*tmp;
    }
}

// command line arguments
int main(int argc, char **argv) {
 
    // argc argument count
    // argv is an array of strings
    if (argc > 2) {
        printf("%d\n", intpow(atoi(argv[1]), atoi(argv[2])));
    }
    return 0;
} 