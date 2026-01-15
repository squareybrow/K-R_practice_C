#include <stdio.h>
#define dprint(expr) printf(#expr " = %i\n", expr);

int strlength(char *s) {
    int n = 0;
    while (*s != '\0') {
        s++;
        n++;
    }
    return n;
}

int strlength2(char *s) {
    char *p = s;
    while (*p != '\0') {
        p++;
    }

    return (p - s);
}

int main(void) {
    dprint(strlength("hello world"));
}