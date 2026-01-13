/*
Exercise 1.15. Rewrite the temperature conversion program of Section 1.2
for conversion.
*/

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahr = lower;
    printf("%3s %6s\n", "Fahr", "Celsius"); // Right aligned
    while (fahr <= upper)
    {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

float fahr_to_celsius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}