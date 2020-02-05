#include <stdio.h>

int main() {

    int a = 0xc5;
    int b = 125;
    int c = 0xA87BDFF3;
    int d = 0b11111111;

    // Is d == 0xFF?

    printf("%d\n", a);
    printf("%x\n", b);  // x format specifier
    printf("%X\n", b);  // x format specifier

    // numbers that start with a leading 0 are in base 
    // 8 aka octal.
    int z = 0125;
    printf("z is %d\n", z);
}