
#include <stdio.h>
#include <string.h>

struct s
{
  char c;
  int i;
};

union u
{
  int i;
  char c;
  float f;
};

struct a
{
  int i;
  char *st1;
};

typedef struct a ST;

int main()
{
/*
  char string1[3] = "xyz";
  char string2[4] = {'x', 'y', 'z', '\0'} ;
  if (strcmp(string1, string2) == 0)
    printf("string1 and string2 are same\n");
  else
    printf("string1 and string2 are not same\n");
*/

  struct s s11;
  printf("sizeof(s) = %ld\n", sizeof(s11));

  union u u1;
  printf("sizeof(u) = %ld\n", sizeof(u1));

  printf("sizeof(int) = %ld sizeof('x') = %ld\n", sizeof(int), sizeof('x'));

  ST *s1;
  s1 = (ST*)malloc(100);
  if(s1)
  {
    s1->i=100;
    s1->st1 = (char *)malloc(sizeof(char)*20);
    strcpy(s1->st1, "Welcome!");
    printf(" %d %s\n", s1->i, s1->st1);
  }
  else
  {
    printf("s1 is null");
  }

  return 0;
}

