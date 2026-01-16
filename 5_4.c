#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);

  if (len_t > len_s) {
    printf("Enter as (longer string, shorter string)\n");
    return -1;
  }
  s += len_s;
  t += len_t;

  int n = 0;

  for (; (*t == *s) && (n < len_t); n++, s--, t--)
    ;

  if (n == len_t) {
    return 1;
  }
  return 0;
}

int main(void) {
  char *strA = "lo";
  char *strB = "Hello";

  printf("String A: %s\n", strA);
  printf("String B: %s\n", strB);

  if (strend(strB, strA)) {
    printf("%s contains %s at the end.\n", strB, strA);
  } else {
    printf("%s doesn't contain %s at the end.\n", strB, strA);
  }
  return 0;
}