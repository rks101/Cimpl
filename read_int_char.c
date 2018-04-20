// Read integer and then a character 
// Notice one side effect of scanf()
#include <stdio.h>

int main()
{
  int n;
  char ch, ch2;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Enter a character: ");
  scanf(" %c", &ch);

  printf("Enter a character: ");
  scanf(" %c", &ch2);

  printf("ch = %c\n", ch);
  printf("ch2 = %c\n", ch2);
  printf("n = %d\n", n);

  return 0;
}
