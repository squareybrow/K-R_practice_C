#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr);
#define swap(t, x, y) {t *p = &(x), *q = &(y), z = *p; *p = *q, *q = z;}

int main(void) {
    int x = 5, y = 10;

    dprint(x);
    dprint(y);
    swap(int, x, y)
    dprint(x);
    dprint(y);
}