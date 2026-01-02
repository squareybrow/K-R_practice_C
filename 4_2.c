#include <math.h>
#include <stdio.h>

double atof(char *s) {
    double val, power;
    double power_e = 0.0;
    int i;
    int sign_val = 1;
    int sign_pow = 1;
    for (i = 0; s[i] == ' '; i++);
    if (s[i] == '+') {
        i++;
    }
    else if (s[i] == '-') {
        sign_val = -1;
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
    if (s[i] == 'e' || s[i] == 'E') i++;
    if (s[i] == '-') {
        sign_pow = -1;
        i++;
    }
    for (power_e = 0.0; s[i] >= '0' && s[i] <= '9'; i++) {
        power_e = (10 * power_e) + (s[i] - '0');
    }
    if (sign_pow == 1) {
        return sign_val * val * pow(10, power_e) / power;
    }
    else if (sign_pow == -1) {
        return sign_val * val / (pow(10, power_e) * power);
    }
    return -1;
}

int main(void) {
    printf("%f\n", atof(" -1.2e-1 "));
}