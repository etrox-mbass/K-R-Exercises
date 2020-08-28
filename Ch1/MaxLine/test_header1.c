#include <stdio.h>
#include <string.h>

void copy(char[], char[]);

int main()
{
    char from[32];
    char to[32];

    strcpy(from, "hello1");
    copy(from, to);
    printf("Array from: %s\n", from);
    printf("Array to: %s\n", to);
    return 0;
}

/**
 * copy: Copy elements of 'from' into 'to', assuming 'to' is big enough.
 */
void copy(char from[], char to[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
