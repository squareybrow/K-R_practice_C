#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum { MAXLINES = 5000, MAXLEN = 1000, ALLOCSIZE = 10000 };

char *lineptr[MAXLINES];

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

void strcpyptr(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

int get_line(char *s, int lim) {
  int i;
  int c = getchar();
  for (i = 0; i < lim - 1 && c != EOF && c != '\n'; i++) {
    s[i] = c;
    c = getchar();
  }
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines = 0;
  char *p, line[MAXLEN];
  while ((len = get_line(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc((len + 1) * sizeof(char))) == NULL) {
      return -1;
    }
    strcpyptr(p, line);
    *(lineptr + nlines++) = p;
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines, int start) {
  for (int i = start; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

int main(int argc, char *argv[]) {
  int nlines, number = 10;

  if (--argc > 0 && *(++argv)[0] == '-') {
    if ((*argv)[1] == 'n') {
      number = atoi(*(++argv));
    }
  }

  else if (argc != 1) {
    printf("Usage: tail -n\n");
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    int start = (nlines > number) ? nlines - number : 0;
    writelines(lineptr, nlines, start);
    return 0;
  } else {
    printf("Error: Input too big to read\n");
    return 1;
  }
}