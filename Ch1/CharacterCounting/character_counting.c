#include <stdio.h>

/* Count characters in input. */

int main()
{
    unsigned long long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%llu\n", nc);

    return 0;
}
