#include <stdio.h>

double atof(char *s) {
    double val, power;
    int i;
    int sign = 1;
    for (i = 0; s[i] == ' '; i++);
    if (s[i] == '+') {
        sign = 1;
        i++;
    }
    else if (s[i] == '-') {
        sign = -1;
        i++;
    }
    for (val = 0.0; (s[i] >= '0' && s[i] <= '9'); i++) {
        val = (10 * val) + (s[i] - '0');
    }
    if (s[i] == '.') i++;
    for (power = 1.0; (s[i] >= '0' && s[i] <= '9'); i++) {
        val = (10 * val) + (s[i] - '0');;
        power *= 10;
    }
    return sign * val / power;
}

int main(void) {
    printf("%f\n", atof("-344.654"));
}