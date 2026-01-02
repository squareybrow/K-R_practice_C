#include <stdio.h>
#include <string.h>

int strrindex(char *s, char *t);

char pattern[] = "aa";

int main(void) {
    char string[] = "aaaaa";
    printf("%i\n", strrindex(string, pattern));
    return 0;
}

int strrindex(char *s, char *t) {
    int i, j, k;
    int string_len = strlen(s);
    int pattern_len = strlen(t);
    for (i = string_len - 1; i >= 0; i--) {
        for (j = i, k = pattern_len - 1; j >= 0 && s[j] == t[k]; j--, k--) {
            if (k == 0) return (i - pattern_len + 1);
        }
    }
    return -1;
}