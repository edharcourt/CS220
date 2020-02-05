#include <stdio.h>

int main() {

    signed char x = 0b10000000;
    x = 0x80;

    // Are characters signed or unsigned?
    printf("%d\n", x);

    int y = 0b10000000000000000000000000000000;
    y = 0x80000000;
    printf("%d\n", y);

    int a, b, c;
    a = 2000000000;
    b = 3000000000;
    c = a + b;
    printf("%d %d\n", a + b, c);

    int z = 0xFFFFFFFF;
    printf("%d\n", z);

    // bitwise negation 
    z = ~0x80000000;
    printf("%d\n", z);

    z = ~0;
    printf("%d\n", z); 

}