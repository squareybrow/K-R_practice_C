#include <stdio.h>
#include <string.h>

void reverse (char *s) {
    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return -1;
    }
    reverse(argv[1]);
    printf("%s\n", argv[1]);
    return 0;
}