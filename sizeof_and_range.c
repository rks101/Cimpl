//
// C Program to find out size and range of int, char, short, and long int 
//
#include <stdio.h>
#define SIZE(x) sizeof(x)*8    // *8 to get size in bits 

void signed_one(int);
void unsigned_one(int);

int main()
{
    // Important: Be cautious here while printing integer values using a format string. e.g., %d, %u, %ld, %lu 
    // - print output of sizeof() using lu => unsigned long 
    // - print output of signed numbers or integers using ld 
    // - print output of unsigned numbers or unsigned integers using lu 
    // Do not use d for unsigned int because -1 is not a valid unsigned integer; see the TRY below. 
    // Do not use u for long int because trying to print a larger value (long int) using a smaller container (int) is incorrect; see the TRY2 below. 
    // 
    // For signed data types: check formula -2^(n-1) to (2^(n-1)) – 1.
    // For unsigned data types: check formula 0 to (2^n) – 1. 
    // here, n is the number of bits, and x^y is the power function x raised to the power of y 
    
    // integer
    printf("\nsize of signed int: %lu", sizeof(int));

    printf("\nrange of int");
    signed_one(SIZE(int));
 
    printf("\nsize of unsigned int: %lu", sizeof(unsigned int));

    printf("\nrange of unsigned int");
    unsigned_one(SIZE(unsigned int));


    // character
    printf("\n\nsize of char: %lu", sizeof(char));
 
    printf("\nrange of char");
    signed_one(SIZE(char));
 
    printf("\nsize of unsigned char: %lu", sizeof(unsigned char));

    printf("\nrange of unsigned char");
    unsigned_one(SIZE(unsigned char));


    // short integer
    printf("\n\nsize of short: %lu", sizeof(short));

    printf("\nrange of short");
    signed_one(SIZE(short));
 
    printf("\nsize of unsigned short: %lu", sizeof(unsigned short));

    printf("\nrange of unsigned short");
    unsigned_one(SIZE(unsigned short));

    
    // long integer
    printf("\n\nsize of signed long int: %lu", sizeof(long));    // both long and long int are the same 

    printf("\nrange of long int");
    signed_one(SIZE(long int));
 
    printf("\nsize of unsigned long int: %lu", sizeof(unsigned long));

    printf("\nrange of unsigned long int");
    unsigned_one(SIZE(unsigned long int));
    
    return 0;
}
 
// get min and max values for signed version 
// << 1 means once bit-wise left shift or multiply by 2 
// ~product means 1's complement of product or invert all bits 
// 
void signed_one(int count)
{
    long int min, max, pro = 1;     
    // TRY2: what should be the correct data type here in the first declaration? 
    // Try using int and see the result and warnings. 
    
    while (count != 1)
    {
        pro = pro << 1;
        count--;
    }
    
    min = ~pro;
    min = min + 1;
    max = pro - 1;
    
    // For long int in the first declaration, use  %ld
    // For int in the first declaration, use  %d 
    // Do not use %u or %lu here because of signed numbers 
    // try out these things and convince yourself that 
    // - we need separate functions for each data type; 
    // - OS & compliers do that to avoid implicit conversions! or side effects.
    printf("\n%ld to %ld", min, max);
}
 
// get min and max values for unsigned version 
// 
void unsigned_one(int count)
{
    unsigned long int min, max, pro = 1;
    // TRY2: what should be the correct data type here in the first declaration? 
    // Try using unsigned int and see the result and warnings. 

    while (count != 0)
    {
        pro = pro << 1;
        count--;
    }
    
    min = 0;
    max = pro - 1;

    // For unsigned long int in the first declaration, use  %lu
    // For unsigned int in the first declaration, use  %u 
    // Do not use %d or %ld here because we are finding out unsigned numbers 
    // try out these things and convince yourself that 
    // - we need separate functions for each data type; 
    // - OS & compliers do that to avoid implicit conversions! or side effects. 

    // TRY! using %d in place of lu in printf below 
    // and convince yourself that -1 for max of unsigned value is incorrect
    // max of some unsigned data type should be an unsigned number only
    printf("\n%lu to %lu", min, max);
}


/*
Sample output on cplayground.com (clang gives better error diagnostics) or onlinegdb.com: 

                                                 Compiling...                                                 
clang++ -o /cplayground/cplayground /cplayground/code.cpp -I/cplayground/include -L/cplayground/lib -std=c++20 -O0 -Wall -no-pie -lm -pthread
                                            Compiled in 230.428 ms                                            
                                                 Executing...                                                 

size of signed int: 4
range of int
-2147483648 to 2147483647
size of unsigned int: 4
range of unsigned int
0 to 4294967295

size of char: 1
range of char
-128 to 127
size of unsigned char: 1
range of unsigned char
0 to 255

size of short: 2
range of short
-32768 to 32767
size of unsigned short: 2
range of unsigned short
0 to 65535

size of signed long int: 8
range of long int
-9223372036854775808 to 9223372036854775807
size of unsigned long int: 8
range of unsigned long int
0 to 18446744073709551615                                      

Execution finished (exit status 0)                                      

*/
