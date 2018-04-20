#include <stdio.h>

int main()
{
  char name[1025];

  // 1. read a string - terminated by ' ', '\n'
  printf("Enter your name: ");
  scanf("%s", name);

  // 2. read a string - till character after ^ is encountered
  //printf("Enter your name: ");
  //scanf("%[^\n]s", name);

  printf("Name: %s\n", name);

  char sid[13];
  printf("Enter your student ID: ");
  scanf("%s", sid);
  printf("Name: %s\n", sid);

  return 0;
}
