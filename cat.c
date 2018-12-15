#include <stdio.h>
#include <string.h>


void dump(FILE* file) {

    char buffer[256];
    while (fgets(buffer, sizeof buffer, file) != 0) {
        fputs(buffer, stdout);
    }
}


int main(int argc, char* argv[]) {

    if (argc == 1) {
        dump(stdin);
    }

    for (int i=1; i<argc; i++) {

        if (strncmp(argv[i], "-", 1) == 0) {

            dump(stdin);

        } else {

            FILE* file = fopen(argv[i], "r");
            if (file != 0) {
                dump(file);
                fclose(file);
            }

        }
    }

    return 0;
}
