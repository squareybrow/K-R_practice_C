#include <stdio.h>
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

void afree(char *p) {
  if ((p >= allocbuf) && (p < allocbuf + ALLOCSIZE)) {
    allocp = p;
  }
}

int main(void) {
  char *p = alloc(sizeof(char) * 100);
  p[0] = 'a';
  p[2] = 'c';
  *(p + 1) = 'b';
  for (int i = 0; i < 10; i++) {
    printf("%c\n", p[i]);
  }
  printf("abc...\n");
  afree(p);
  char *q = alloc(100);
  q[0] = 'd';
  for (int i = 0; i < 10; i++) {
    printf("%c\n", p[i]);
  }
  return 0;
}