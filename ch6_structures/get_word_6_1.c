#include <stdio.h>
#include <ctype.h>

int get_word(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch())) {};

    if (c != EOF) {
        *w++ = c;
    }
    if (c == '\"') {
        *w++ = c;
        while ((*w = getch()) != '\"') {
            w++;
        }
        return c;
    }
    if (c == '#') {
        *w++ = c;
        while ((*w = getch()) != '\n') {
            w++;
        }
        return c;
    }
    if (c == '_') {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        *w = getch();
        if (!isalnum(*w) && (*w != '_')) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}