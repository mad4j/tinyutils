#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc == 1) {
        putchar('\0');
        return 1;
    }

    unsigned long count = 0;

    for (int i=1; i<argc; i++) {

        long times = strtol(argv[i], 0, 10);

        for (int k=0; k<times; k++) {
            putchar('\0');
            count++;
        }
    }

    return count;
}
