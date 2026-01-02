#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getlines(char *s, int lim);
int strindex(char *pattern, char *s);

char pattern[] = "ijk";
int cnt = -1;
int len;

int main(void) {
    char line[] = "abcdef\nghijk";
    int found = 0;
    char *start;

    while ((len = getlines(start = (line + cnt + 1), MAXLINE)) > 0) {
        if (strindex(pattern, start) >= 0) {
            found++;
            printf("%s\n", start);
        }
        if (cnt + 1 >= strlen(line)) {
            break;
        }
        else {
            cnt += len + 1;
        }
    }
    printf("%i\n", found);
    return found;
}

int getlines(char *s, int lim) {
    int i;
    for (i = 0; s[i] != '\0' && --lim > 0; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            return i;
        }
    }
    if (s[i] == '\0') {
        return i;

    }
    return -1;
}

int strindex(char *pattern, char *s) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] != '\0' && s[j] == pattern[k]; j++, k++);
        if (k > 0 && pattern[k] == '\0') {
            return i;
        }
    }
    return -1;
}