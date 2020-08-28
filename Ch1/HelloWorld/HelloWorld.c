#include <stdio.h>

/**
 * A program to print out an escape sequence \ followed by a possible ASCI
 * character.
 */

int main(int argc, char** argv)
{
    char c;
    for (c = 0; c >= 0; c++) {
        printf("ASCII code %d character %c: \%c\n", c, c, c);
    }

    return 0;
}
