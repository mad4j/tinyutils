#include <stdio.h>

int main() {

    unsigned long count = 0;

    int c = 0;
    while ((c = getchar()) != EOF) {

        if ((count % 16) == 0) {
            printf("\n %08lx ", count);
        }

        printf(" %02x", c);

        count++;
    }

    printf("\n %08lx\n", count);

    return count;
}