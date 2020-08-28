#include <stdio.h>
#define MAXLINE 256        /* Maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/*
 * Revise the main routine from max_line program so it will correctly print
 * the length of arbitrarily long input lines, and as much as possible of the
 * text.
 */
int
main()
{
    int len;                /* Current line length */
    int max;                /* Maximum length seen so far */
    int c;                  /* Temporary character to read from stdio */
    char line[MAXLINE];     /* Current input line */
    char longest[MAXLINE];  /* Longest line saved here */

    max = 0;
    len = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (line[MAXLINE-2] != '\n') {
            while ((c = getchar()) != '\n')
                ++len;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    
    if (max > 0)
        printf("Longest line has: %d\n", max);
    return 0;
}

/**
 * getline: read a line into s, return length
 */
int
get_line(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/**
 * copy: copy 'from' into 'to'; assume 'to' is big enough.
 */
void
copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
