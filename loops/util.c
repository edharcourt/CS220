
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

// returned the numbers of ones in the binary representation
// of x
int popcount(int x) {
    int sum = 0;
    while (x > 0) {
        sum = sum + (x & 1);
        x = x >> 1;
    }
    return sum;
}

