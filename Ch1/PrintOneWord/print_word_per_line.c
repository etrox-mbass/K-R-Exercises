#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/**
 * A program that prints one word per line from input
 */

int
main()
{
    int c, prev, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (prev == ' ' || prev == '\t' || prev == '\n')
                ;
            else
                putchar('\n');
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else {
            putchar(c);
        }

        prev = c;
    }
}
