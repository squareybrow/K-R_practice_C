#include <stdio.h>
#define dprint(expr) printf(#expr " = %c\n", expr);

int main(void) {
    char *str[3] = {"HELLO", "SLATE", "TARES"};
    dprint(*++(str)[2]);
    dprint(*++str[2]);
}