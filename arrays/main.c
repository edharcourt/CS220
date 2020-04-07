#include "scale.h"
#include <stdio.h>
#include <stdlib.h>

void print_vec(int *vec, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d\n", vec[i]);    
}

int main(int argc, char *argv[]) {
    
    int *vec = malloc((argc - 1)*sizeof(int));
    int i = 1;
    while (i < argc) {
        vec[i-1] = atoi(argv[i]);
        i++;
    }
    scale(vec, argc - 1, 20);
    print_vec(vec, argc - 1);
    return 0;
}
