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
    0,  1,  1,  2,  1,  2,  2,  3,  1,  2,  2,  3,  2,  3,  3,  4,  1,  2,  2,  3,  2,  3,  3,  4,
    2,  3,  3,  4,  3,  4,  4,  5,  1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,
    2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,  1,  2,  2,  3,  2,  3,  3,  4,  
    2,  3,  3,  4,  3,  4,  4,  5,  2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,  
    2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,  3,  4,  4,  5,  4,  5,  5,  6,  
    4,  5,  5,  6,  5,  6,  6,  7,  1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,  
    2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,  2,  3,  3,  4,  3,  4,  4,  5,  
    3,  4,  4,  5,  4,  5,  5,  6,  3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,  
    2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,  3,  4,  4,  5,  4,  5,  5,  6,  
    4,  5,  5,  6,  5,  6,  6,  7,  3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,  
    4,  5,  5,  6,  5,  6,  6,  7,  5,  6,  6,  7,  6,  7,  7,  8,
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
            100 * ((double)zerosCount / totalCount)
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
