/*
 *   Separate compilation
 */

#include <stdio.h>
#include "sqr.h"

extern int f(int a, int b, int c);

int main() {
    printf("%d\n", f(10,20,30));
    printf("%d\n", sqr(33));
}