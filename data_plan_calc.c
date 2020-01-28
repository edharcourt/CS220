#include <stdio.h>
#include <math.h>

int main() {

    double size = 6*pow(2,30)*8; 
    double bandwidth = 64e3;

    printf("Hours: %.2f\n", size/bandwidth/3600);

    // 10 mbps internet connection
    // download 10 GiB file. How long will it take?
    size = 10*pow(2,30)*8;
    bandwidth = 10e6;
    printf("Hours: %.2f\n", size/bandwidth/3600);

    return 0;
}