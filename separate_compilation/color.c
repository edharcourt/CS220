#include <stdio.h>

int avg(int r, int g, int b) {
    return (r + g + b) / 3;
}

int main() {
    printf("%d\n", avg(243,129,77));
}
