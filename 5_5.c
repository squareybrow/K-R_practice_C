#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strncpyptr(char *s, char *t, int n) {
  for (int i = 0; i < n; i++) {
    *s++ = *t++;
  }
}

char *strncatptr(char *s, char *t, int n) {
  int len_s = strlen(s);
  int len_t = strlen(t);

  int len;
  if (n < len_t)
    len = n;
  else
    len = len_t;

  char *result = malloc((len_s + len + 1) * sizeof(char));
  if (result == NULL)
    return NULL;
  char *start = result;

  while ((*result++ = *s++))
    ;
  result--;

  while (len > 0) {
    *result++ = *t++;
    len--;
  }
  *result = '\0';

  return start;
}

int main(void) {
  char strA[20] = "Hello ";
  char strB[20] = "World";

  printf("String A: %s\n", strA);
  printf("String B: %s\n", strB);

  char *strC = strncatptr(strA, strB, 3);
  printf("Concatenated String: %s\n", strC);

  strncpyptr(strA, strB, 3);
  printf("Copied String: %s\n", strA);

  free(strC);

  return 0;
}
