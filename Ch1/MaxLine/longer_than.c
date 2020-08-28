#include <stdio.h>

#define MAXLINE 1000    /* The maximum number of characters in a line */
#define WIDTH 80        /* The number of characters that can fit on one line
                            of the screen */

/**
 * A program that prints all input lines that are longer than 80 characters.
 */
int get_line(char s[], int lim);
void copy(char from[], char to[]);

int
main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len >= 80)
            printf("%s", line);
    }

    return 0;
}

int
get_line(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}

void
copy(char from[], char to[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
