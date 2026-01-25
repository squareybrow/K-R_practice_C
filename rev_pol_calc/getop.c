#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"


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