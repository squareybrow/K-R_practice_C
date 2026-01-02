#include <stdio.h>
#include <math.h>

int main(void) {
    int size_int = sizeof(int) * 8;
    double min_int = -pow(2, size_int - 1);
    double max_int = pow(2, size_int - 1) - 1;

    printf("Size of int in bits: %d\n", size_int);
    printf("Range of int is from %f to %f\n", min_int, max_int);

    double max_uint = pow(2, size_int) - 1;
    printf("Range of unint is from 0 to %f\n", max_uint);
}