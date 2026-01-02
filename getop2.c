#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER '0'
enum {MAXVAL = 100};

int sp = 0;
double val[MAXVAL];
int pos = 0;
char input[] = " -5 -6 - 7.1 + sin";

int getop(char *s) {
    int i = 0;
    char c;
    for (; input[pos] == ' ' || input[pos] == '\t'; pos++);

    c = input[pos];

    if (isalpha(c)) {
        char str[MAXVAL];
        int j = 0;

        while (isalpha(input[pos])) {
            str[j++] = input[pos++];
        }
        str[j] = '\0';

        if (strcmp(str, "sin") == 0) return 's';

        return 0;
    }

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

double print_stack(void) {
    if (sp > 0) return val[sp - 1];
    printf("stack empty\n");
    return 0.0;
}

void duplicate_element(void) {
    if (sp > 0) {
        if (sp < MAXVAL) {
            val[sp] =  val[sp - 1];
            sp++;
        }
        else {
            printf("stack full\n");
        }
    }
    else {
        printf("stack empty\n");
    }
}

void swap_elements(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else printf("not enough elements in stack\n");
}

void clear_stack(void) {
    sp = 0;
    printf("stack cleared\n");
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