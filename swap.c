#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr);

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int x = 5, y = 6;
    dprint(x);
    dprint(y);

    swap(&x, &y);
    dprint(x);
    dprint(y);
}