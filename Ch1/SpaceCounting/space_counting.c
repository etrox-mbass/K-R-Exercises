#include <stdio.h>

/**
 * Count blanks, tabs, and newlines characters from input.
 */

int
main()
{
    int nb, nt, nl, c;
    nb = nt = nl = 0;

    while ((c = getchar()) != EOF) {
        switch(c) {
            case ' ':
                ++nb;
                break;
            case '\t':
                ++nt;
                break;
            case '\n':
                ++nl;
                break;
            default:
                break;
        }
    }
    printf("%32s\t%32s\t%32s\n", "blanks", "tabs", "lines");
    printf("%32d\t%32d\t%32d\n", nb, nt, nl);
    return 0;
}
