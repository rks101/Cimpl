#include <stdio.h>

#define PRN printf("%d %d %d %d %d %d \n", a[0], a[1], a[2], a[3], a[4], a[5]);

int main()
{
	int a[]={0, 1, 2, 3, 4, 5};
	PRN
	a[5, 2]=7;
	PRN
  
  // Q. what is printed by second PRN? Does this even work? 
	return 0;
}
