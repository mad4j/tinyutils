/**
 * cksum - compute a very simple checksum
 * daniele.olmisani@gmail.com
 */

#include <stdio.h>
#include <stdint.h>

int main() 
{

    uint32_t sum = 0;

    int c = 0;
    while ((c = getchar()) != EOF) {

        sum += 33 * (0xff & c);
    }

    printf("0x%04X\n", sum);

    return sum;
}