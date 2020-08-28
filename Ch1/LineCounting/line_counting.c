#include <stdio.h>

int main()
{
    unsigned long lc;
    int c;
    for (lc = 0; (c = getchar()) != EOF;)
        if (c == '\n') lc++;

    printf("%lu\n", lc);
    return 0;
}
