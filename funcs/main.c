#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// main -> f -> g

/*
void g(int x) { 
    return abs(x) + x;      
}

int f(int y) {
    int x = g(y);
    return x;
}
*/

int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

//int max4(int w, int x, int y, int z) {
//    return max(max(w, x), max(y, z));
//}

// return a random integer between [x,y)
int randrange_c(int x, int y) {
    // rand() returns a random integer between 0 and RAND_MAX 2^32 - 1
    // y = 20 x = 10
    return rand() % (y - x) + x;
}

extern int randrange(int x, int y);
extern int max4(int w, int x, int y, int z);
extern int f(int);


int array_sum_c(int *vec, int n) {
    int sum = 0;
    int i = 0;
    
    while (i < n) {
        sum = sum + vec[i];
        i++;
    }
    return sum;
}
extern int array_sum(int *vec, int n);

void array_scalar_mult(int *vec, int n, int s) {
    // vec[i] = vec[i] * s;
    int i = 0;
    while (i < n) {
        vec[i] = vec[i] * s;
        i++;
    }
}

int main() {
    
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("%d\n", array_sum(nums, 10));
    
    // seed the random number generator
    srand(time(NULL));
    printf("%d\n", randrange(100,200));
    printf("%d\n", randrange(100,200));
    
    printf("%d\n", max4(1, 2, 3, 4));
    printf("%d\n", max4(99, 0, 3, -15));
    //printf("%d %d\n", f(7), f(-7)); 
    return 0;
}
