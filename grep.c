#include <stdio.h>
#include <string.h>

enum {MAXLINE = 1000};

int get_line(char *line, int lim) {
  int i = 0;
  int c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF  && c != '\n'; i++) {
    line[i] = c;
  }
  line[i] = '\0';
  return i;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: grep <pattern>");
    return -1;
  }

  char line[MAXLINE];
  int found = 0;
  while (get_line(line, MAXLINE) > 0) {
    if (strstr(line, argv[1]) != NULL) {
      printf("%s\n", line);
      found++;
    }
  }
  return found;
}