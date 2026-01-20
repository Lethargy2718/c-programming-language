/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define nl putchar('\n')
#define sp printf("------\n")

int main(void)
{

    /*
        sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

        This is the general rule. The exact values depend on architecture
    */

    printf("Signed Char:\n\n");
    printf("Manual:\n");
    printf("Min: %d\n", -(int)((unsigned char)~0 >> 1) - 1);

    // 00000000..   0 is an int literal so it's int sized by default
    // 11111111..   ~0 negates all zeros. still int sized
    // 11111111     (unsigned char) cast truncates to 8 bits and causes shifts to be logical instead of arithmetic
    // 01111111     >> 1 does a logical right shift
    // 01111111     convert to int
    // 10000001     - produces the two's comp
    // 10000000     -1 subtracts one to create the min number

    // the other data types go through a similar process

    printf("Max: %d\n", (int)((unsigned char)~0 >> 1));

    nl;

    printf("Lib:\n");
    printf("Min: %d\n", SCHAR_MIN); // -128
    printf("Max: %d\n", SCHAR_MAX); // 127

    sp;

    printf("Unsigned Char:\n\n");

    printf("Manual:\n");
    printf("Max: %d\n", (unsigned char)~0);

    nl;

    printf("Lib:\n");
    printf("Max: %d\n", UCHAR_MAX); // 255

    sp;

    printf("Signed Short:\n\n");
    printf("Manual:\n");
    printf("Min: %d\n", -(int)((unsigned short)~0 >> 1) - 1);
    printf("Max: %d\n", (int)((unsigned short)~0 >> 1));

    nl;

    printf("Lib:\n");
    printf("Min: %d\n", SHRT_MIN); // -32768
    printf("Max: %d\n", SHRT_MAX); // 32767

    sp;

    printf("Unsigned Short:\n\n");

    printf("Manual:\n");
    printf("Max: %d\n", (unsigned short)~0);

    nl;

    printf("Lib:\n");
    printf("Max: %d\n", USHRT_MAX); // 65535

    sp;

    printf("Signed int:\n\n");
    printf("Manual:\n");
    printf("Min: %d\n", -(int)((unsigned)~0 >> 1) - 1);
    printf("Max: %d\n", (int)((unsigned)~0 >> 1));

    // NOTE: (unsigned) by itself is shorthand for (unsigned int)

    nl;

    printf("Lib:\n");
    printf("Min: %d\n", INT_MIN); // -2147483648
    printf("Max: %d\n", INT_MAX); // 2147483647

    sp;

    printf("Unsigned int:\n\n");
    printf("Manual:\n");
    printf("Max: %u\n", ~0); // (unsigned) cast here is unnecessary thanks to %u

    nl;

    printf("Lib:\n");
    printf("Max: %u\n", UINT_MAX); // 4294967295

    sp;

    printf("Signed Long:\n\n");
    printf("Manual:\n");
    printf("Min: %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
    printf("Max: %ld\n", (long)((unsigned long)~0 >> 1));

    nl;

    printf("Lib:\n");
    printf("Min: %ld\n", LONG_MIN); // -9223372036854775808
    printf("Max: %ld\n", LONG_MAX); // 9223372036854775807

    sp;

    printf("Unsigned Long:\n\n");

    printf("Manual:\n");
    printf("Max: %lu\n", (unsigned long)~0);

    nl;

    printf("Lib:\n");
    printf("Max: %lu\n", ULONG_MAX); // 18446744073709551615

    sp;

    printf("Signed Long Long:\n\n");
    printf("Manual:\n");
    printf("Min: %lld\n", -(long long)((unsigned long long)~0 >> 1) - 1);
    printf("Max: %lld\n", (long long)((unsigned long long)~0 >> 1));

    nl;

    printf("Lib:\n");
    printf("Min: %lld\n", LLONG_MIN); // -9223372036854775808
    printf("Max: %lld\n", LLONG_MAX); // 9223372036854775807

    sp;

    printf("Unsigned Long Long:\n\n");

    printf("Manual:\n");
    printf("Max: %llu\n", (unsigned long long)~0);

    nl;

    printf("Lib:\n");
    printf("Max: %llu\n", ULLONG_MAX); // 18446744073709551615

    sp;

    printf("Float:\n\n");
    printf("Lib:\n");
    printf("Min: %e\n", FLT_MIN);
    printf("Max: %e\n", FLT_MAX);

    sp;

    printf("Double:\n\n");
    printf("Lib:\n");
    printf("Min: %e\n", DBL_MIN);
    printf("Max: %e\n", DBL_MAX);

    sp;

    printf("Long Double:\n\n");
    printf("Lib:\n");
    printf("Min: %Le\n", LDBL_MIN);
    printf("Max: %Le\n", LDBL_MAX);

    sp;
}