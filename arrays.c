#include <stdio.h>

// global variable
// It is visible in all functions. Do not use them!
// Unless Harcourt says so
int a_global_variable;

void f(char chs[], int n) {
    // n is the size of the array

    // arrays are passed by reference
    chs[0] = ';';
}

int main() {

    // variables defined inside of a function are called local
    int vec[10];  // an array of ten integers

    printf("%d\n", vec[5]);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", vec[i]);         
    }

    // Array index ourt of bounds
    // printf("%d\n", vec[10000]);

    char symbols[] = {'!', '#', '&', '%', '\''};
    char syms[] = "!#&%\'";

    for (int i = 0; i < 5; i++) {
        printf("%c\n", symbols[i]);
    }

    f(symbols, 5);
    printf("%c\n", symbols[0]);

}