#include <stdio.h>
#include <string.h>

char *itob(int n, char *s, int b) {
    int rem = 0;
    int k = 0;
    while (n > 0) {
        rem = n % b;
        n /= b;
        if (rem < 10) {
            s[k++] = '0' + rem;
        }
        else if (rem >= 10) {
            s[k++] = 'A' + rem - 10;
        }
    }

    s[k] = '\0';
    int len = strlen(s);

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int main(void) {
    char str[100];
    printf("%s\n", itob(15, str, 16));
}