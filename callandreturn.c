
#include <stdio.h>

void h() {
    printf("I'm in h");
}

void g() {
    printf("Calling h");
    h();
}

void f() {
    printf("Calling g");
    g();
    printf("Calling h");
    h();
}

int main() {
    f();
    return 1;
}
