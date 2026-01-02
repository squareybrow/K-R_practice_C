#include <stdio.h>
int atoi(char s[]) {
    int num = 0;
    int i = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '+') {
        i++;
    }
    if (s[i] == '-') {
        i++;
        while (s[i] >= '0' && s[i] <= '9') {
            num = (num * 10) - (s[i] - '0');
            i++;
        }
        return num;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        num = (num * 10) + (s[i] - '0');
        i++;
    }

    return num;
}

int main(void) {
    printf("%i\n", atoi("-2147483648"));
}