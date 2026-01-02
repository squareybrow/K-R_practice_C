#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }
    printf("%i\n", setbits(atoi(argv[1]), 4, 3, atoi(argv[2])));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0U << n);
    x = x & ~(mask << (p + 1 - n));
    y = (y & mask) << (p + 1 - n);
    return (y | x);
}