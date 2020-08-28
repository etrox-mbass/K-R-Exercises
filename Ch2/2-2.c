#include <stdio.h>
#include <string.h>
#include <assert.h>
#ifndef DEBUG
#define DEBUG 0
#endif
#define BUF_SZ 32

int get_line1(char s[], int lim);
int get_line2(char s[], int lim);

/**
 * Rewrite the for loop in get_line1 so that get_line2 accomplish the same
 * goal as get_line1 without using logical operators || and &&
 */

int
main()
{
    int len1, len2;
    char line1[BUF_SZ];
    char line2[BUF_SZ];

    len1 = get_line1(line1, BUF_SZ);
    len2 = get_line2(line2, BUF_SZ);
    if (DEBUG) {
        printf("Line1: %s", line1);
        printf("Line2: %s", line2);
    }
    assert(strcmp(line1, line2) == 0);
    return 0;
}

int
get_line1(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n';++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int
get_line2(char s[], int lim)
{
    int i, c;
    i = 0;
    while (i < lim-1) {
        if ((c = getchar()) != EOF) {
            if (c != '\n')
                s[i++] = c;
            else
                break;

        } else {
            break;
        }
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
