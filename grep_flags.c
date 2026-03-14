// grep -x -n <pattern> where -x is except and -n is number

#include <endian.h>
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

    char line[MAXLINE];
    int c, except = 0, number = 0, found = 0, line_no = 0;

    while ((--argc > 0) && (*(++argv)[0] == '-')) {
        while ((c = *(++argv[0]))) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                printf("Illegal option -%c\n", c);
                return -1;
            }
        }
    }

    if (argc != 1) {
        printf("Usage: grep -x -n <pattern>\n");
        return -1;
    }

    while (get_line(line, MAXLINE) > 0) {
        line_no++;
        if ((strstr(line, *argv) != NULL) != except) {
            if (number) {
                printf("%i\t", line_no);
            }
            printf("%s\n", line);
        }
        found++;
    } 
    return found;
}