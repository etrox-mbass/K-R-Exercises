#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define LOWER 0     /* Lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */


void print_usage();
void fahr_to_celsius();
void fahr_to_celsius_for(int);
void celsius_to_fahr();

int
main(int argc, char** argv)
{
    if (argc != 2)
        print_usage();

    switch(atoi(argv[1])) {
        case 1:
            //fahr_to_celsius();
            fahr_to_celsius_for(1);
            break;
        case 2:
            celsius_to_fahr();
            break;
        default:
            print_usage();
            break;
    }

    return 0;
}

void
print_usage()
{
    printf("Usage: temp_converter [option]\n");
    printf("Option 1: Printing a table of temperature from Fahrenheit to Celsius.\n");
    printf("Option 2: Printing a table of temperature from Celsius to Fahrenheit.\n");
    exit(0);
}

/* Print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */

void
fahr_to_celsius()
{
    float fahr, celsius;
    
    printf("A table of temperature from Fahrenheit to Celsius.\n");
    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

void fahr_to_celsius_for(int reverse)
{
    int fahr;
    printf("A table of temperatur from Fahrenheit to Celsius.\n");
    if (reverse)
        for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
            printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    else
        for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
            printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
}

/* Print Celsius-Fahrenheit table.
 */
void
celsius_to_fahr()
{
    float fahr, celsius;

    printf("A table of temperature from Celsius to Fahrenheit.\n");
    celsius = LOWER;
    while (celsius <= UPPER) {
        fahr = celsius * (9.0/5.0) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
}
