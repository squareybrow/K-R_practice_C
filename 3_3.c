#include <ctype.h>
#include <stdio.h>
char *expand(char *s1, char *s2) {
    int k = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i+1] == '-' && s1[i+2] != '\0' &&
            ((isdigit(s1[i]) && isdigit(s1[i+2])) || (islower(s1[i]) && islower(s1[i+2])) || (isupper(s1[i]) && isupper(s1[i+2])))) {
            if (s1[i+2] > s1[i]) {
                for (char j = s1[i]; j <= s1[i + 2]; j++) {
                    s2[k++] = j;
                }
            }
            else if (s1[i+2] < s1[i]) {
                for (char j = s1[i]; j >= s1[i + 2]; j--) {
                    s2[k++] = j;
                }
            }
             i+= 2;
        }
        else {
            s2[k++] = s1[i];
        }
    }
    s2[k] = '\0';
    return s2;
}

int main(void) {
    char s2[100];
    printf("%s\n", expand("a-z0-9z-a",s2));
}