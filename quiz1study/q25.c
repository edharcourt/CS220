
#include <stdio.h>

int sum_of_decimal_digits(int x) {
    if (x == 0)
        return 0;

    return (x % 10) + sum_of_decimal_digits(x / 10);
}

int sum_of_bits(int x) {
    if (x == 0)
        return 0;

    return (x & 1) + sum_of_bits(x >> 1);
}

int main() {
    printf("%d\n", sum_of_decimal_digits(12345));
    printf("%d\n", sum_of_bits(0x10001111));
    return 0;
}
