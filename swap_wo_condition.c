// Swap two integers without using a third variable
#include <stdio.h>

int main()
{
  int x, y;

  printf("Enter two numbers: ");
  scanf("%d%d", &x, &y);

  printf("Before swap: x = %d, y = %d\n", x, y);

  x = x + y;
  y = x - y;
  x = x - y;

  printf("After swap: x = %d, y = %d\n", x, y);

  return 0;
}

