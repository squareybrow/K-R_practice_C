#include <stdio.h>
#include <string.h>
#include <math.h>

int htoi(char *s);

int main(void) {
    printf("%d\n", htoi("0x17CF"));
    return 0;
}

int htoi(char *s) {
    int len = strlen(s);
    int result = 0;
    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;
    for (; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            result += (s[i] - '0') * pow(16, len - i - 1);
        }
        else if (s[i] >= 'A' && s[i] <='F') {
            result += (s[i] - 'A' + 10) * pow(16, len - i - 1);
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            result += (s[i] - 'a' + 10) * pow(16, len - i -1);
        }
    }
    return result;
}