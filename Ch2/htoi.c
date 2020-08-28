/**
 * htoi.c: Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A thourgh F.
 */

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

int htoi(char s[])
{
    int n, i, len;
    len = strlen(s);
    n = 0;

    if (len >= 2) {
        if (s[0] == 0 && tolower(s[1]) == 'x')
            i = 2;
        else
            i = 0;
    } else {
        i = 0;
    }

    for (; i < len; i++) {
        if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
            n += (int) (10 + (tolower(s[i]) - 'a')) * pow(16, len - i - 1);
        else if (s[i] >= '0' && s[i] <= '9')
            n += (int) (s[i] - '0') * pow(16, len - i - 1);
    }

    return n;
}

int main(int argc, char** argv)
{
    printf("Testing htoi function...\n");

    char test1[] = "0xA";
    char test2[] = "0XA";
    char test3[] = "AB";
    char test4[] = "0x1234567";
    char test5_err[] = "0xgA";
    char test6[] = "0xFFF123A";
    char test7[] = "0x7fffffff";
    printf("Size of int: %d\n", sizeof(int)); 
    printf("Test1 conversion: %d\n", htoi(test1));
    assert(htoi(test1) == 10);
    printf("Test2 conversion: %d\n", htoi(test2));
    assert(htoi(test2) == 10);
    printf("Test3 conversion: %d\n", htoi(test3));
    assert(htoi(test3) == 171);
    printf("Test4 conversion: %d\n", htoi(test4));
    assert(htoi(test4) == 19088743);
    printf("Test5_err conversion: %d\n", htoi(test5_err));
    assert(htoi(test5_err) == 10);
    printf("Test6 conversion: %d\n", htoi(test6));
    assert(htoi(test6) == 268374586);
    printf("Test7 conversion: %d\n", htoi(test7));
    assert(htoi(test7) == 2147483647);
    return 0;
}
