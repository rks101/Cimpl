//
// C Program to find out size and range of int, char, short
//
#include <stdio.h>
#define SIZE(x) sizeof(x)*8    // *8 to get size in bits 

void signed_one(int);
void unsigned_one(int);

int main()
{
    // Important: Be cautious while printing integer values using a format string. e.g., %d or %u 
    // print output of sizeof() using lu => unsigned long
    // print output of signed numbers or integers using d
    // print output of unsigned numbers or unsigned integers using u, 
    // do not use d for unsigned int because -1 is not a valid unsigned integer, see the TRY below. 
    // 
    // For signed data types: check formula -2^(n-1) to (2^(n-1)) – 1.
    // For unsigned data types: check formula 0 to (2^n) – 1. 
    // here, n is the number of bits in both cases, and ^ is the power function. 
    
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

    
    return 0;
}
 
// get min and max values for signed version 
// << 1 means once bit-wise left shift or multiply by 2 
// ~product means 1's complement of product or invert all bits 
// 
void signed_one(int count)
{
    int min, max, pro = 1;
    
    while (count != 1)
    {
        pro = pro << 1;
        count--;
    }
    
    min = ~pro;
    min = min + 1;
    max = pro - 1;
    
    // do not use %u here because of signed numbers 
    printf("\n%d to %d", min, max);
}
 
// get min and max values for unsigned version 
// 
void unsigned_one(int count)
{
    unsigned int min, max, pro = 1;
 
    while (count != 0)
    {
        pro = pro << 1;
        count--;
    }
    
    min = 0;
    max = pro - 1;

    // TRY! using d in place of u in printf below 
    // and convince yourself that -1 for max of unsigned value 
    // should be some unsigned number only
    printf("\n%u to %u", min, max);
}


/*
Sample output: 

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

*/
