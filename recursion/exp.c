int slowpow(int x, int y) {
    if (y == 0)
        return 1;
    else 
        return x * slowpow(x, y - 1);
}

/*
 *  computing x**y  1024/2 -> 512 -> 256 -> 128 -> 64 - ... 1 log2(y)
 * 
 *  Variant of this algorithm called "modular exponentiation" 
 *  cryptography.   
 */
int fastpow(int x, int y) {
    if (y == 0)   // base case 
        return 1;
    else if (y & 1)  // odd case
        return x * fastpow(x, y - 1);
    else {
        int tmp = fastpow(x, y >> 1);   // even case
        return tmp*tmp;
    }
}

// x**7 -> x*x**6 -> x * (x**3)**2 and so on
