// What is return value of printf() and scanf()
// 1. Run this with input as 4 2
// 2. Run this with input as 4.2
#include <stdio.h>

int main()
{
  int num1, num2;
  long int sum;
  int ret_val = 0;

  sum = num1 = num2 = 0;

  printf("Enter two integers: ");

  if ((ret_val = scanf("%d%d", &num1, &num2)) == 2)
  {
    sum = num1 + num2;
    ret_val = 0;
    ret_val = printf("sum = %ld\n", sum);

    printf("ret_val = %d\n", ret_val);
  }
  else
  {
    printf("ret_val = %d\n", ret_val);
    printf("Something unexpected happened!\n");
  }

  return 0;
}
