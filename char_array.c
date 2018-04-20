
#include <stdio.h>

int main()
{
  char names[5][20] = {"Haskell", "Go", "Scala", "C", "C++"};

  int i;
  char *t;

  t = names[3];
  names[3] = names[4];
  names[4] = t;

  for (i = 0; i <= 4; i++)
  {
    printf("%s", names[i]);
  }

  // Q. What is wrong with this program? 
  // Can you fix it?

  return 0;
}

