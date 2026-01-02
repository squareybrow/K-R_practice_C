#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER '0'
enum {MAXVAL = 100};

int sp = 0;
double val[MAXVAL];
int pos = 0;
char input[] = " -6 -5 - 7.1 +";

int getop(char *s) {
    int i = 0;
    char c;
    for (; input[pos] == ' ' || input[pos] == '\t'; pos++);

    c = input[pos];

    if (!isdigit(c) && c != '.' && c != '-') {
        pos++;
        return c;
    }

    else if (c == '-') {
        char next = input[++pos];
        if (!isdigit(next) && next != '.') return c;

        s[i++] = c;
    }

    for(; isdigit(c = input[pos]); pos++) {
        s[i++] = c;
    }

    if (input[pos] == '.') {
        s[i++] = input[pos++];
        for (; isdigit(c = input[pos]); pos++) {
            s[i++] = c;
        }
    }

    s[i] = '\0';

    return NUMBER;
}

void push(double f) {
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full\n");
}

double pop(void) {
    if (sp > 0) return val[--sp];
    printf("stack empty\n");
    return 0.0;
}

int main(void) {
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
    }
    printf("%f\n", val[0]);
    return 0;
}