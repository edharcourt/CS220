#include <stdio.h>
#include <math.h>

int main() {
    double bandwidth = 600e3; // 600 Kbps
    double time_in_sec = 3600;
    int one_MiB = 1 << 20; // ooooh, fancy. Why is this one MiB? 
    double size = (time_in_sec * bandwidth) / 8 / one_MiB;
    printf("Size (MiB): %.1f\n", size);

    return 0;
}
