#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    printf("%i\n", rightrot(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    n %= sizeof(unsigned) * 8;
    unsigned mask = ~(~0U << n);
    unsigned temp = (x & mask) << ((sizeof(unsigned) * 8) - n);
    return (x >> n) | temp;
}