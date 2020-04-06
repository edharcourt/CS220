int slowpow(int x, int y) {
    if (y == 0)
        return 1;
    else 
        return x * slowpow(x, y - 1);
}

int fastpow(int x, int y) {
    if (y == 0) 
        return 1;
    else if (y & 1)
        return x * fastpow(x, y - 1);
    else {
        int tmp = fastpow(x, y >> 1);
        return tmp*tmp;
    }
}
