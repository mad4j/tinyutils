/** 
 * zeroc - counts 0 bits on the standard input
 * https://mad4j.github.io/tinyutils/
 * 
 * daniele.olmisani@gmail.com
 * 
 * see LICENSE file
 */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

unsigned char ZEROS[] = {
    8,  7,  7,  6,  7,  6,  6,  5,  7,  6,  6,  5,  6,  5,  5,  4, 
    7,  6,  6,  5,  6,  5,  5,  4,  6,  5,  5,  4,  5,  4,  4,  3, 
    7,  6,  6,  5,  6,  5,  5,  4,  6,  5,  5,  4,  5,  4,  4,  3, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    7,  6,  6,  5,  6,  5,  5,  4,  6,  5,  5,  4,  5,  4,  4,  3, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    5,  4,  4,  3,  4,  3,  3,  2,  4,  3,  3,  2,  3,  2,  2,  1, 
    7,  6,  6,  5,  6,  5,  5,  4,  6,  5,  5,  4,  5,  4,  4,  3, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    5,  4,  4,  3,  4,  3,  3,  2,  4,  3,  3,  2,  3,  2,  2,  1, 
    6,  5,  5,  4,  5,  4,  4,  3,  5,  4,  4,  3,  4,  3,  3,  2, 
    5,  4,  4,  3,  4,  3,  3,  2,  4,  3,  3,  2,  3,  2,  2,  1, 
    5,  4,  4,  3,  4,  3,  3,  2,  4,  3,  3,  2,  3,  2,  2,  1, 
    4,  3,  3,  2,  3,  2,  2,  1,  3,  2,  2,  1,  2,  1,  1,  0
};


void usage() {
    printf("usage: zeroc [-lh]\n");
    printf("       counts zero bits in input stream\n");
    printf("   -l  long report\n");
    printf("   -h  this messge\n");
}


void report(bool longReportFlag, unsigned long zerosCount, unsigned long totalCount)
{
    if (longReportFlag) {

        printf("%ld / %ld (%2.2f%%)\n", 
            zerosCount, 
            totalCount, 
            100 * ((double)zerosCount / (double)totalCount)
        );
    } else {
        printf("%ld", zerosCount);
    }
}


int main(int argc, char** argv)
{
    unsigned long zerosCount = 0;
    unsigned long totalCount = 0;

    bool longReportFlag = false;

    int c = 0;
    while ((c = getopt(argc, argv, "lh")) != -1) {
        switch (c) {
        case 'l':
            longReportFlag = true;
            break;
        case 'h':
            usage();
            return 0;
        default:
            break;
        }
    }

    while ((c = getchar()) != EOF) {
        zerosCount += ZEROS[c];
        totalCount += 8;
    }

    report(longReportFlag, zerosCount, totalCount);

    return zerosCount;
}
