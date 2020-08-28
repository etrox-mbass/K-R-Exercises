#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#ifndef DEBUG
#define DEBUG 0
#endif

#define BUF_SZ 2   /* Initial maximum buffer size */

/**
 * A program that reverses its input a line at a time.
 */

void reverse(char *a);
char* get_line(char *s);

int
main()
{
    int len;
    char *input_buffer;

    input_buffer = (char*) malloc(sizeof(char) * BUF_SZ);
    if (input_buffer == NULL) {
        fprintf(stderr, "ERROR: Cannot allocate memory for input_buffer.\n");
        exit(1);
    }

    while (strlen(input_buffer = get_line(input_buffer)) > 0) {
        reverse(input_buffer);
        printf("%s", input_buffer);
    }

    free(input_buffer);
    return 0;
}

/**
 * reverse: reverse all elements in character array 'a'.
 * Assuming array 'a' is null terminated.
 */
void reverse(char *a)
{
    int i, j, temp;
    for (i = 0; a[i] != '\0'; ++i)
        ;
    if (DEBUG) printf("String length: %d\n", i);
    j = 0; --i;
    while (j < i) {
        if (DEBUG) printf("Swapping index %d with index %d. Resulting array: %s\n", j, i, a);
        temp = a[j];
        a[j++] = a[i];
        a[i--] = temp;
    }
}

/**
 * get_line: Get an arbitrary size line from input stream. Returns the length of the line.
 * */
char* get_line(char *s)
{
    int i, c;
    int max_size = BUF_SZ;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i >= max_size - 1) {
            max_size = max_size << 1;
            s = (char*) realloc(s, sizeof(char) * max_size);
            if (s == NULL) {
                fprintf(stderr, "ERROR: Cannot reallocate memory for buffer s.\n");
                exit(1);
            }
        }
        s[i++] = c;
    }

    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return s;
}

void tester()
{
    if (DEBUG) {
        printf("Testing reverse() with string \"hello\"\n");
        char a[6];
        strcpy(a, "hello");
        reverse(a);
        printf("%s\n", a);
        assert(strcmp("olleh", a) == 0); 
    }
}
