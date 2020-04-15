#include <stdio.h>
#include "merge.h"
#include "mergesort.h"

int main() {
    
    int vec1[] = { 6, 10, 46, 69, 78 };
    int vec2[] = { 14, 24, 29, 43, 95, 98 };
    
    int *vec3 = merge(vec1, 5, vec2, 6);
    
    for (int i = 0; i < 11; i++) {
        printf("%d ", vec3[i]);
    }
    printf("\n");
    
    int blob[] = { 69, 46, 10, 78, 6, 29, 24, 43, 95, 14, 98 };
    mergesort(blob, 11);

    for (int i = 0; i < 11; i++) 
        printf("%d ", blob[i]);
    printf("\n");
    
    return 0;
}
