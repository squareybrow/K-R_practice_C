#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int pos = 0;
char input[] = "-5 -6 - 7.1 + cos";

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXVAL];

    while ((type = getop(s)) != '\0') {
        if (type == NUMBER) push(atof(s));
        else if (type == '+') push(pop() + pop());
        else if (type == '*') push(pop() * pop());
        else if (type == '-') {
            op2 = pop();
            push(pop() - op2);
        }
        else if (type == '/') {
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: division by zero");
        }
        else if (type == '%') {
            op2 = pop();
            if (op2 != 0.0) push(fmod(pop(), op2));
            else printf("error: division by zero");
        }
        else if (type == 's') {
            push(sin(pop()));
        }
        else if (type == 'e') {
            push(exp(pop()));
        }
        else if (type == '^') {
            op2 = pop();
            push(pow(pop(), op2));
        }
    }
    printf("%f\n", val[0]);
    return 0;
}