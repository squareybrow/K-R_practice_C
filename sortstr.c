#include <stdio.h>
#include <string.h>

int main(void) {
  char *st[] = {"apple", "Air", "ball", "zebra", "cat"};
  int n = 5;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(st[j], st[j + 1]) > 0) {
        char *temp = st[j];
        st[j] = st[j + 1];
        st[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%s\n", st[i]);
  }
  return 0;
}