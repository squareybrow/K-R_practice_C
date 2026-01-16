#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcatptr(char *s, char *t) {
  int len_s = strlen(s);
  int len_t = strlen(t);
  int len_res = len_s + len_t;

  char *result = malloc((len_res + 1) * sizeof(char));
  char *start = result;

  while ((*result++ = *s++))
    ;
  result -= 1;
  while ((*result++ = *t++))
    ;
  return start;
}

int main(void) {
  char *strA = "Hello ";
  char *strB = "World";

  printf("String A: %s\n", strA);
  printf("String B: %s\n", strB);

  char *strC = strcatptr(strA, strB);
  printf("Concatenated String: %s\n", strC);

  free(strC);

  return 0;
}