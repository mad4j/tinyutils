#include <stdio.h>
#include <ctype.h>

int main() {

    int c = 0;
    while ((c = getchar()) != EOF) {

        char b = (isalpha(c)) ? (isupper(c)) ? 'A' : 'a' : 0; 
        putchar((b>0) ? b + (((c-b)+13)%26) : c);
    }

    return 0;
}
