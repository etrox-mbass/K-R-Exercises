#include <stdio.h>
#include <ctype.h>

/**
 * A program that copies its input to its output, replacing each string of one
 * or more blanks by a single blank.
 */

int
main()
{
    int c, prev;

    while ((c = getchar()) != EOF) {
        if (isspace(c) && c == prev) {
            continue;
        } else {
            prev = c;
            putchar(c);
        }
    }
}
