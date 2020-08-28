#include <stdio.h>
#include <string.h>

/**
 * This program is used to demonstrate pre and post prefix increment
 */

int
main()
{
    int i = 0, j = 5;
    char a[6];
    strcpy(a, "hello");
    printf("Value of the expression with prefix incrementing ++i: %d\n", ++i);
    i--;
    printf("value of the expression with postfix incrementing i++: %d\n", i++);
    return 0;
}
