
/*
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}
*/

// study question, implement this in assembly
int max(int x, int y) {
    if (x < y)
        x = y;
    return x;
}

int absmax(int x, int y) {
    return max(abs(x), abs(y));
}

// returned the numbers of ones in the binary representation
// of x, assume x >= 0.
int popcount(int x) {
    int sum = 0;
    while (x > 0) {
        sum = sum + (x & 1);
        x = x >> 1;  // lsr
    }
    return sum;
}

// if we list all of the natural numbers below 10 that are multiples of 
// 3 or 5we get 3, 5, 6, 9, and the sum is 23.
int sum_3_or_5(int n) {
      // returns the sum of the numbers below n that are 
      // multiples of 3 or 5.
} 
