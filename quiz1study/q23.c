#include <stdio.h>
#include <math.h>

static const unsigned int bits_in_int = sizeof(int)*8;

unsigned int rotate_once(const unsigned int x) {
    int bits = bits_in_int - 1;
    return ((x & 1) << bits) | (x >> 1);
}

unsigned int rotate_loop(const unsigned int x, const unsigned int n) {
    unsigned int tmp = x;

    for (int i = 0; i < n; i++)
        tmp = rotate_once(tmp);

    return tmp;    
}

unsigned int rotate(const unsigned int x, const unsigned int n) {

    unsigned int n_ones = 0b11111111111111111111111111111111 >> (bits_in_int - n);
    unsigned int lower_bits = x & n_ones;
    unsigned int upper_bits = lower_bits << (bits_in_int - n);
     
    unsigned int result = (x >> n) | upper_bits;

    return result;
}

int main() {

    unsigned int test = 0b11001101011110101011110001100011;

    printf("%x\n", rotate(test, 5));
    printf("%x\n", rotate_loop(test, 5));
    return 0;
}
