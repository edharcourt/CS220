#include <stdio.h>

#define BITS_IN_INT 32

// Compute the sum of the digits of a decimal number
// 1234 = 10
int sum_of_decimal_digits(int n) {
     int sum = 0;
     while (n > 0) {
         sum = sum + n % 10;
         n  = n / 10;
    }
    return sum;
}

int sum_of_bits(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum + (n & 0b1);
        n = n >> 1;
    }   
    return sum;
}

// write sum of digits and sum of bits recursively.



void print_bin(int n) {
    if (n == 0) {
        //printf("0");
    }
    else {
        print_bin(n >> 1);
        printf("%d", n & 0b1);
    }
}

void print_binary(int n) {
    const int bits_in_int = 32;
    
    char bits[bits_in_int];
    int i = 0;
    
    while (n > 0) {
        bits[i++] = n & 0b1;     
        n = n >> 1;   // >> is shift right
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }  
    printf("\n");
}


int main() {
    print_bin(0);
    print_bin(0b110111101);
    printf("\n");
    return 0;
}
