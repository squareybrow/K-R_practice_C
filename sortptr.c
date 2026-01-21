#include <stdio.h>
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

void swap(char **s, char **t) {
  char *temp = *s;
  *s = *t;
  *t = temp;
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

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

int partition(char *lineptr[], int start, int end) {
  char *pivot = lineptr[end];
  int i = start - 1;

  for (int j = start; j < end; j++) {
    if (strcmp(lineptr[j], pivot) < 0) {
      i++;
      swap(lineptr + i, lineptr + j);
    }
  }
  i++;
  swap(lineptr + i, lineptr + end);
  return i;
}

void quick_sort(char *lineptr[], int start, int end) {
  if (end <= start)
    return;

  int pivot = partition(lineptr, start, end);
  quick_sort(lineptr, start, pivot - 1);
  quick_sort(lineptr, pivot + 1, end);
}

int main(void) {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    quick_sort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("Error: Input too big to sort\n");
    return 1;
  }
}