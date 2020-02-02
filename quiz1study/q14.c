#include <stdio.h>
#include <math.h>

int main() {
    double bandwidth = 15e6; // 15 Mbps
    double size = 4*pow(2,30)*8; // 4 GiB in bits
    double time_in_sec = size/(bandwidth*60);
    printf("Time (min): %.1f\n", time_in_sec);

    return 0;
}
