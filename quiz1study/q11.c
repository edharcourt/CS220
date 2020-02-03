
#include <stdio.h>

int main() {
    int sum = 0;
    int n = 14;
   
     while (n > 0) {
         sum = sum + n % 2;
         n = n / 2;
     }

     printf("%d\n", sum);        
}
