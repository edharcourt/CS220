#include <stdlib.h> // malloc

int main() {
    int *p;

    // a *memory leak*, the program just keeps using more and more 
    // memory and never reclaims it.
    while (1) {
        p = malloc(sizeof(int));
        free(p);  // reclaim the memory
    }
}