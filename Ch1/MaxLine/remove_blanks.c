#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define BUFF_SZ 1000
#ifndef DEBUG
#define DEBUG 0
#endif

/**
 * A program to remove trailing blanks and tabs from each line of input, and to
 * delete entirely blank lines.
 */

int get_line(char s[], int lim);
void remove_trailing_blanks(char s[]);

int
main()
{
    int len;
    char line[BUFF_SZ];
    
    if (DEBUG) {
        char s[32];
        strcpy(s, "hello     ");
        remove_trailing_blanks(s);
        assert(strcmp(s, "hello\n") == 0);

        strcpy(s, "           ");
        remove_trailing_blanks(s);
        assert(strcmp(s, "") == 0);

        strcpy(s, "hello");
        remove_trailing_blanks(s);
        assert(strcmp("hello", s) == 0);
        printf("All test cases for remove_trailing_blanks passed.\n");
    }
    
    while ((len = get_line(line, BUFF_SZ)) > 0) {
        remove_trailing_blanks(line);
        printf("%s", line);
    }
    return 0;    
}

/**
 * get_line: Copy a line from stdin to a buffer 's' with limit.
 */
int
get_line(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/**
 * remove_trailing_blanks: Remove trailing blank space
 */
void
remove_trailing_blanks(char s[])
{
    int i, lc;
    lc = 0;
    for (i = 0; s[i] != '\0'; ++i) {
        if (!isspace(s[i]))
            lc = i;
    }
    
    if (lc == 0) {
        s[lc] = '\0';
    } else if (s[lc+1] != '\0') {
        s[lc+1] = '\n';
        s[lc+2] = '\0';
    }
}
