#include <math.h>
#include <stdio.h>
#include <ctype.h>
#define dprint(expr) printf(#expr " = %f\n", expr);

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getfloat(float *pn) {
    int c;
    int sign = 1;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }

    if (c == '-' || c == '+') {
        if (c == '-') {
            sign = -1;
        }
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            if (sign == '-') {
                ungetch('-');
            }
            else {
                ungetch('+');
            }
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * (*pn) + (c - '0');
    }

    if (c == '.') {
        c = getch();
        for (int i = 1; isdigit(c); c = getch(), i++) {
            *pn += (c - '0') / pow(10, i);
        }
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int main(void) {
    float n;
    int result;

    printf("Enter an Integer: ");
    result = getfloat(&n);

    dprint(n);

    return 0;
}
