#include <stdio.h>

int main() {
    printf("char is %d bytes\n", sizeof(char));
    printf("short is %d bytes\n", sizeof(short));
    printf("int is %d bytes\n", sizeof(int));
    printf("long is %d bytes\n", sizeof(long));
    printf("long long is %d bytes\n", sizeof(long long));
    printf("float is %d bytes\n", sizeof(float));
    printf("double is %d bytes\n", sizeof(double));
    printf("(void *) is %d bytes\n", sizeof(void *));
}
