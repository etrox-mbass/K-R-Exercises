#include <stdio.h>

/**
 * Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\
 */

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        switch(c) {
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("\\\\");
                break;
            default:
                putchar(c);
                break;
        }
    }

    return 0;
}
