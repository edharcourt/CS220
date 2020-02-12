#include <string.h>    // strlen
#include <stdio.h>     // printf
#include <stdlib.h>    // malloc

int main() {

    int i = 12345;
    int *j = &i;   

    printf("%d\n", i);
    printf("0x%x\n", j);

    *j = 88;     // follow the pointer 
    printf("%d\n", i);

    // *j is an alias of i
    // an alias is another name for a variable (storage)

    // j = 0;       segmentation fault
    // *j = 12345;

    char *str;

    // allocate memory for the string;
    //str[0] = 'h';
    //str[1] = 'e';
    char *tmp = "Hello world";   // a C string constant
    str = malloc(strlen(tmp));   // allocate however many bytes
                                 // tmp is 
    char *saved = str;
 
    // copy tmp in to str
    while (*tmp != '\0') {
        *str = *tmp;
        str++;
        tmp++;
    }

    *str = '\0';
    printf("DEBUG %s\n", saved);
} 