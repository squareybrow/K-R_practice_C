#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum {MAXWORD = 100};

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0
};

#define NKEYS (sizeof keytab) / sizeof(struct key)

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

struct key *binsearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid -> word)) < 0) high = mid;
        else if ((cond = strcmp(word, mid -> word)) > 0) low = mid + 1;
        else return mid;
    }
    return NULL;
}

int main(void) {
    char word[MAXWORD];
    struct key *p;
    while (get_word(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL) {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s", p -> count, p->word);
        }
    }
    return 0;
}