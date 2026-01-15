#include <ctype.h>
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

int getint(int *pn) {
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

  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
    return 0;
  }

  return c;
}

int main(void) {
  int n, result;
  printf("Enter an integer: ");
  result = getint(&n);

  printf("n = %d\nresult = %d", n, result);

  return 0;
}