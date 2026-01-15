#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  if (bufp > 0) {
    return buf[--bufp];
  } else {
    return getchar();
  }
}

int ungetch(int c) {
  if (bufp > BUFSIZE) {
    printf("Error. Buffer Overflow. Exiting...");
    return -1;
  } else {
    buf[bufp++] = c;
    return 0;
  }
}

int getfloat(float *pn) {
  int c, sign = 1;

  while (isspace(c = getch())) {
  };

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  if (c == '-' || c == '+') {
    if (c == '-') {
      sign *= -1;
    }
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      if (sign == '-') {
        ungetch('-');
      } else {
        ungetch('+');
      }
      return 0;
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * (*pn) + (c - '0');
  }

  if (c == '.') {
    c = getch();
    for (int i = 1; isdigit(c); c = getch(), i++) {
      *pn += (c - '0') / pow(10, i);
    }
  }

  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
    return 0;
  }

  return c;
}

int main(void) {
  float n;
  int result;
  printf("Enter an integer: ");
  result = getfloat(&n);

  printf("n = %f\nresult = %d\n", n, result);

  return 0;
}