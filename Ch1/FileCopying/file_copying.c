#include <stdio.h>

/* Copy input to output */

int
main()
{
    int c;
    printf("Starting the copying program...\n");
    printf("Value of EOF is: %d\n", EOF);
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
