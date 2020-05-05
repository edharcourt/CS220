#include <string.h>
#include <stdlib.h>
#include "merge.h"

void mergesort(int *vec, int n) {
    
    if (n < 2) return;
    
    mergesort(vec, n/2);
    
    // vec + n/2 is base address + offset
    mergesort(vec + n/2, n - n/2);
    int *r = merge(vec, n/2, vec + n/2, n - n/2);    
    memcpy(vec, r, n*sizeof(int));
    free(r);  // make sure we don't leak memory
    
    return;
}
