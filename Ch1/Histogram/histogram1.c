#include <stdio.h>

#define IN 1            /* inside a word */
#define OUT 0           /* outside a word */
#define MAX_LEN 32      /* Max size of a word in the given natural language, in this case English */
#ifndef DEBUG
#define DEBUG 0         
#endif
#ifndef HORIZONTAL
#define HORIZONTAL 1    /* Print the histogram horizontally. 0 for vertically */
#endif

/**
 * A program that print a histogram of the lengths of words in its input. It is
 * easy to draw the histogram with the bars horizontal; a vertical orientation
 * is more challenging.
 */

int
main()
{
    int i, j, prev, c, state, input_max_len, cur_len;
    int len_freq_table[MAX_LEN];
    
    input_max_len = 0;
    for (i = 0; i < MAX_LEN; ++i)
        len_freq_table[i] = 0;
    
    state = OUT;
    cur_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (cur_len != 0)
                ++len_freq_table[cur_len];
            cur_len = 0;
            state = OUT;
            if (prev == ' ' || prev == '\t' || prev == '\n')
                ;
            else
                if (DEBUG == 1)
                    putchar('\n');
        } else if (state == OUT) {
            state = IN;
            cur_len = 1;
            if (DEBUG == 1) putchar(c);
        } else {
            ++cur_len;
            if (cur_len > input_max_len)
                input_max_len = cur_len;
            if (DEBUG == 1) putchar(c);
        }

        prev = c;
    }

    if (HORIZONTAL == 1) {
        for (i = 1; i <= input_max_len; ++i) {
            printf("%d\t%d\t", i, len_freq_table[i]);
            for (j = 0; j < len_freq_table[i]; ++j)
                printf("-");
            printf("\n");
        }
    } else {
    }
}
