#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    for (int i = 3; i < n; i++) 
        if (i % 3 == 0 || i % 5 == 0)
            sum = sum + i;

    printf("Answer: %d\n", sum);
    return 0;
}
