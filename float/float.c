#include <stdio.h>

int main() {

    float x = .09;  // 32 bit representation in memory
    int *y = (int *) &x;  // cast the float pointer to an int pointer

    printf("%X\n", *y);
}
