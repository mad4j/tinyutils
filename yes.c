#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {

    while(true) {
        puts((argc == 1) ? "y" : argv[1]);
    }

    return 0;
}
