// Do you love to compare two real numbers?
#include <stdio.h>

int main()
{
  char i = 65;
  int j = 'z';
  printf("%d %c\n", i, i);
  printf("%d %c\n", j, j);

  float me = 1.1;
  double you = 1.1;

  if (me == you)
    printf("I love U\n");
  else
    printf("I hate U\n");

  return 0;
}
