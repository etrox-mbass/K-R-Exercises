#include <stdio.h>
#include <assert.h>
#include <string.h>

/**
 * Contains the squeeze function and exercise 2-4, 2-5 in K&R
 */

/*
 * squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
            s[j++] = s[i];
    }

    s[j] = '\0';
}

/*
 * strcat: concatenate t to end of s; s must be big enough */
void krstrcat(char s[], char t[])
{
    int i, j;
    
    i = j = 0;
    while(s[i] != '\0')
        i++;
    while((s[i++] = t[j++]) != '\0')
        ;
}

/**
 * Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */
void squeeze24(char s1[], char s2[])
{
    // O(n^2) version: for each character in s1, check if it exists in s2.
    // If it does, delete it from s1.

    // Solution that reuses the original squeeze function.
    int i;

    for (i = 0; s2[i] != '\0'; i++)
        squeeze(s1, s2[i]);
}

/**
 * streq: returns 0 if 2 strings s1 and s2 are the same and -1 otherwise. 
 */
int streq(char s1[], char s2[])
{
    int s1_len, s2_len, i;
    s1_len = s2_len = 0;
    for (; s1[s1_len] != '\0'; s1_len++)
        ;
    for (; s2[s2_len] != '\0'; s2_len++)
        ;
    if (s1_len != s2_len) {
        return -1;
    } else {
        for (i = 0; i < s1_len; i++)
            if (s1[i] != s2[i])
                return -1;
        return 0;
    }
}

/**
 * Exercise 2-5: Write the function any(s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 *  strpbrk does the same job but returns a pointer to the location.)
 */
int any(char s1[], char s2[])
{
    int i, j, min;

    min = -1;
    for (i = 0; s2[i] != '\0'; i++) {
        for (j = 0; s1[j] != '\0'; j++) {
            if (s1[j] == s2[i] && (min == -1 || j < min))
                min = j;
        }
    }
    return min;
}

int main(int argc, char** argv)
{
    // Testing squeeze24(s1, s2)
    printf("Testing the squeeze24 function...\n");
    char s1[] = "This is a sentence for deletion.";
    char s2[] = "absdfsd";
    squeeze24(s1, s2);
    printf("%s\n", s1);
    assert(streq(s1, "Thi i  entence or eletion.") == 0);

    char s3[] = "This is another string for testing purpose.";
    char s4[] = "313fdf";
    squeeze24(s3, s4);
    printf("%s\n", s3);
    assert(streq(s3, "This is another string or testing purpose.") == 0);


    // Testing any(s1, s2)
    char s5[] = "This is a sentence";
    char s6[] = "asbc";
    printf("s5: %s\n", s5);
    printf("s6: %s\n", s6);
    int res = any(s5, s6);
    assert(any(s5, s6) == 3);
    char *c = strpbrk(s5, s6);
    printf("strpbrk returns %d\n", (int) (c - s5));
    assert(any(s5, s6) == (int) (c - s5));

    char s7[] = "Another test case.";
    char s8[] = "xm";
    c = strpbrk(s7, s8);
    assert(c == NULL);
    assert(any(s7, s8) == -1);
    printf("s7: %s\n", s7);
    printf("s8: %s\n", s8);
    printf("strpbrk returns %p\n", c);
    return 0;
}
