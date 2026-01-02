#include <stdio.h>

int any(char *s1, char *s2);

int main(void) {
    char s1[] = "owl";
    char s2[] = "lxy";
    printf("%i\n", any(s1, s2));
    return 0;
}

int any(char *s1, char *s2) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) return i;
        }
    }
    return -1;
}