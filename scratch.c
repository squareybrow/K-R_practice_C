#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr);

int main(void) {
  int x = 1, y = 2, z[10] = {9, 2, 3, 4, 5, 6, 7, 8, 6, 1};
  dprint(x);
  dprint(y);
  int *ip;
  ip = &x;
  dprint(*ip);
  y = *ip;
  *ip = 0;
  ip = &z[0];
  dprint(x);
  dprint(y);
  dprint(*ip);
}
