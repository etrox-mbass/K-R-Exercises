#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void reverse(char s[]);

/**
 * Contains code and exercise from section 2.9 of K&R.
 */

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/**
 * Exercise 2-6
 * setbits: returns x with the n bits that begin at position p set to the
 * right most n bits of y, leaving the other bits unchanged.
 */
unsigned setbits(unsigned x, int p, int n, int y)
{
    // Not correct.
    return (x | (getbits(y, n-1, n) << (p - n + 1)));
}

/**
 * Exercise 2-7
 * invert: returns x with the n bits that behind at position p inverted (i.e.,
 * 1 changed into 0 and vice versa), leaving the others unchanged.
 */
unsigned invert(unsigned x, int p, int n)
{
    // Not correct.
    return ( x |  (~getbits(x, p, n) << (p - n + 1)) );
}

/**
 * Exercise 2-8
 * rightrot(x, n): returns the value of the integer x rotated to the right by
 * n bit positions.
 */
unsigned rightrot(unsigned x, int n)
{
    return 1;
}

/**
 * int_to_bitstr: returns a character string of an integer x in its binary
 * form. Doesn't account for 2s complement.
 */
char* int_to_bitstr(int x)
{
    int i, temp;
    char *bitstr;
    
    bitstr = (char*) malloc(65 * sizeof(char));
    if (bitstr == NULL) {
        fprintf(stderr, "ERROR allocating memory for bitstr\n");
        exit(1);
    }

    for (i = 0; i < 64; i++)
        bitstr[i] = 0;
    bitstr[64] = '\0';
    i = 0;
    temp = x;
    bitstr[i] = 0;

    if (x < 0)
        temp = -x;

    while (temp > 0) {
        bitstr[i++] = temp % 2 + '0';
        temp = temp >> 1;
    }

    bitstr[i+1] = '\0';

    reverse(bitstr);
    return bitstr;    
}

/**
 * reverse: Reverse a character array in place.
 */
void reverse(char s[])
{
    int i, j, c;
    i = j = 0;
    while(s[j++] != '\0')
        ;
    j -= 2;

    while (i < j) {
        c = s[i];
        s[i++] = s[j];
        s[j--] = c;
    }

}

int main(int argc, char** argv)
{
    int i;

    // Testing reverse().
    printf("Testing reverse\n");
    char s[] = "Hello World";
    char s1[] = "123456789";
    char s2[] = "racecar";

    printf("Test case 1: %s\t", s);
    reverse(s);
    printf("%s\n", s);
    printf("Test case 2: %s\t", s1);
    reverse(s1);
    printf("%s\n", s1);
    printf("Test case 3: %s\t", s2);
    reverse(s2);
    printf("%s\n", s2);

    // Testing int_to_bitstr()
    printf("Testing int_to_bitstr\n");
    int test_ints[] = {134, 128, 256, 1024, 512, 43, 3, 4}; 
    for (i = 0; i < 8; i++) {
        printf("%d is %s in binary.\n", test_ints[i], int_to_bitstr(test_ints[i]) );
    }

    // Testing setbits(x, p, n, y)
    int x = 134;
    int y = 43;
    printf("Expecting 10101110. Got: %s\n", int_to_bitstr(setbits(x, 6, 5, y)));

    x = 0b1000111010111; // 4567
    y = 134;
    printf("Expecting 1000111010111. Got: %s\n", int_to_bitstr(setbits(x, 7, 3, y)));

    // Testing invert
    printf("Expecting 1000100101111. Got: %s\n", int_to_bitstr(invert(x, 7, 5)));

    return 0;
}
