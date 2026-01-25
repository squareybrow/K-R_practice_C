#include <stdio.h>
#include "calc.h"

int sp = 0;
double val[MAXVAL];

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