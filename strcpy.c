void strcpyarr(char *s, char *t) {
  int i = 0;
  while ((s[i] = t[i]) != '\0') {
    i++;
  }
}

void strcpyptr(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

int strcmparr(char *s, char *t) {
  int i = 0;

  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') {
      return 0;
    }
  }

  return s[i] - t[i];
}

int strcmpptr(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}
