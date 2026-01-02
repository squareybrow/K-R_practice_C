#include <stdio.h>

void squeeze(char *s1, char *s2);

int main(void) {
    char s1[] = "owl";
    char s2[] = "A quick brown fox jumped over the lazy dog";
    squeeze(s1, s2);
    printf("S1: %s\tS2: %s\n", s1, s2);
    return 0;
}

void squeeze(char *s1, char *s2) {
    int i, j;
    for (i = 0, j = 0; s2[i] != '\0'; i++) {
        int match = 0;
        for (int k = 0; s1[k] != '\0'; k++) {
            if (s2[i] == s1[k]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            s2[j++] = s2[i];
        }
    }
    s2[j] = '\0';
}