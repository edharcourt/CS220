int h(int x) {
   h(x-1);
   return x;
}

int g(int x) {
   int y = x * x;
   return y;
}

int f(int x, int y) {
   int z = g(x) + g(y);
   return z;
}

int main() {
    h(0xFFFFFFFF);
    printf("%d\n", f(3,4));
    return 0;
}