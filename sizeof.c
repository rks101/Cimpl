// Use sizeof operator to find out size for data types
#include <stdio.h>

int main()
{
    printf("sizeof(char): %ld \n", sizeof(char));

    printf("sizeof(short): %ld \n", sizeof(short));
    printf("sizeof(int): %ld \n", sizeof(int));
    printf("sizeof(long): %ld \n", sizeof(long));
    printf("sizeof(unsigned long int): %ld \n", sizeof(unsigned long int));

    printf("sizeof(float): %ld \n", sizeof(float));
    printf("sizeof(double): %ld \n", sizeof(double));
    printf("sizeof(long float): %ld \n", sizeof(long double));

    printf("sizeof('A'): %ld \n", sizeof('A'));
    printf("sizeof(0): %ld \n", sizeof(0));
    printf("sizeof(NULL): %ld \n", sizeof(NULL));

    return 0;
}
