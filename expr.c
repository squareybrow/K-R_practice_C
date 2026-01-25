#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100
#define NUMBER '0'

int sp = 0;
double val[MAXVAL];
int pos = 0;
char input[1000];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full\n");
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  printf("stack empty\n");
  return 0.0;
}

double print_stack(void) {
  if (sp > 0)
    return val[sp - 1];
  printf("stack empty\n");
  return 0.0;
}

void duplicate_element(void) {
  if (sp > 0) {
    if (sp < MAXVAL) {
      val[sp] = val[sp - 1];
      sp++;
    } else {
      printf("stack full\n");
    }
  } else {
    printf("stack empty\n");
  }
}

void swap_elements(void) {
  if (sp > 1) {
    double temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;
  } else
    printf("not enough elements in stack\n");
}

void clear_stack(void) {
  sp = 0;
  printf("stack cleared\n");
}

int getop(char *s) {
  int i = 0;
  char c;

  // Skip whitespace
  for (; input[pos] == ' ' || input[pos] == '\t'; pos++)
    ;

  c = input[pos];

  // Handle alphabetic functions
  if (isalpha(c)) {
    char str[MAXVAL];
    int j = 0;

    while (isalpha(input[pos])) {
      str[j++] = input[pos++];
    }
    str[j] = '\0';

    if (strcmp(str, "sin") == 0)
      return 's';
    if (strcmp(str, "cos") == 0)
      return 'c';
    if (strcmp(str, "exp") == 0)
      return 'e';
    if (strcmp(str, "pow") == 0)
      return 'p';

    return 0;
  }

  // Handle operators and special characters
  if (!isdigit(c) && c != '.' && c != '-') {
    pos++;
    return c;
  }

  // Handle negative numbers
  if (c == '-') {
    char next = input[pos + 1];
    if (!isdigit(next) && next != '.') {
      pos++;
      return c; // It's a minus operator
    }
    s[i++] = c;
    pos++;
  }

  // Handle integer part
  for (; isdigit(c = input[pos]); pos++) {
    s[i++] = c;
  }

  // Handle decimal part
  if (input[pos] == '.') {
    s[i++] = input[pos++];
    for (; isdigit(c = input[pos]); pos++) {
      s[i++] = c;
    }
  }

  s[i] = '\0';
  return NUMBER;
}

int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXVAL];

  // Build input string from command line arguments
  input[0] = '\0';
  for (int i = 1; i < argc; i++) {
    strcat(input, argv[i]);
    if (i < argc - 1)
      strcat(input, " ");
  }

  while ((type = getop(s)) != '\0' && type != '\n') {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;
    case 's':
      push(sin(pop()));
      break;
    case 'c':
      push(cos(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case 'p':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  printf("\t%.8g\n", pop());
  return 0;
}