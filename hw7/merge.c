#include "merge.h"
#include <stdlib.h>

int *merge(int *vec1, int n1, int *vec2, int n2) {
    int i1 = 0;  // current location in vec1
    int i2 = 0;  // current location in vec2
    int i3 = 0;  // current location in the resulting array
    
    int *vec3 = malloc((n1 + n2) * sizeof(int));
    
    while (i1 < n1 && i2 < n2)
        vec3[i3++] = vec1[i1] < vec2[i2] ? vec1[i1++] : vec2[i2++];
            
    // finish copying vec1 (if there is any left to copy)
    while (i1 < n1)                 // idomatic C
        vec3[i3++] = vec1[i1++];    // post-increment
        
    while (i2 < n2)
        vec3[i3++] = vec2[i2++];
    
    return vec3; 
}

/*
     Conditional expression
     
     if (a < b)
         c = a;
     else
         c = b;
        
     c = a < b ? a : b;
     
     cond ? truevalue : falsevalue
          
 */
 
 
 
 
