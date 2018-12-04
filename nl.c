#include <stdio.h>
#include <stdbool.h>

int main() {

  bool check = true;
  unsigned long lines = 0;

  int c = 0;
  while ((c = getchar()) != EOF) {

    if (check) {
      printf("%6lu : ", ++lines);
    }

    putchar(c);

    check = (c == '\n');
  }

  return lines;
}
