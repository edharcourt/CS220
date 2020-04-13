#include <stdio.h>

typedef unsigned char bit; 
typedef unsigned int uint32;  // unsigned int 32 bits
typedef unsigned char byte;

// get the kth bit of an integer
//  get(4, 0b10010011) = 1   lsb is bit 0  
bit get(int k, uint32 n) {
    return (n >> k) & 0b1;
}

// set the kth bit of an integer to 1
// and return the new integer
//  set(5, 0b10010011) = 0b10110011 
//    0b00100000
//  | 0b10010011
//    0b10110011  

uint32 set(int k, uint32 n) {
     return (1 << k) | n;
}

// x = 0b11011
// y = 0b01111
//     =======
// r 
uint32 add(uint32 x, uint32 y) {

    bit c = 0;  // initial carry in in least significant bit
    bit s = 0;  // sum bit  
    bit a, b;   // bits extracted from x and y
    uint32 r = 0;
    int i = 0;  // bit index 
    
    while (i < sizeof(uint32)*8) {
        a = get(i, x);  // get the ith bit of x
        b = get(i, y);
        s = a ^ b ^ c;  // compute the sum
        c = a&b | a&c | b&c;
        if (s) r = set(i, r);  // new result set bit i of old result
        i++;
    }
    
    return r;
}

uint32 mult(uint32 multiplicand, uint32 multiplier) {
    
    uint32 product = 0;
    int i = 0;
    
    while (i < sizeof(uint32)*8) {
        if (multiplier & 1)
            product = add(product, multiplicand);
        
        multiplicand = multiplicand << 1;
        multiplier = multiplier >> 1;
        i++;
    }
    return product;
}


int main() {
    printf("%d %d\n", add(123,987), 123+987);
    printf("%d %d\n", mult(123,987), 123*987);
    
}
