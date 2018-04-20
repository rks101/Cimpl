// C program to illustrate differences
// between structure and Union
#include <stdio.h>
#include <string.h>
 
// declaring structure
struct struct_example
{
  int RollNumber;
  float CGPA;
  char name[20];
};
 
// declaraing union
union union_example
{
  int RollNumber;
  float CGPA;
  char name[20];
};
 
int main()
{
  // creating variable for structure and initializing values
  // difference six

  struct struct_example s={2, 9.2, "YourName"};

  // creating variable for union and initializing values

  union union_example u={2, 9.2, "YourName"};

  printf("structure data:\n RollNumber: %d\n CGPA: %.2f\n name: %s\n", 
    s.RollNumber, s.CGPA, s.name);
  printf("\nunion data:\n integeer: %d\n CGPA: %.2f\n name: %s\n", 
    u.RollNumber, u.CGPA, u.name);
 
  // difference two and three
  printf("\nsizeof structure : %ld\n", sizeof(s));
  printf("sizeof union : %ld\n", sizeof(u));
 
  // difference five
  printf("\n Accessing all members at a time:");
  printf("\n---------------------------------\n");

  s.RollNumber = 183;
  s.CGPA = 10;
  strcpy(s.name, "YourName");

  printf("\nstructure data:\n RollNumber: %d\n CGPA: %.2f\n name: %s\n", 
    s.RollNumber, s.CGPA, s.name);
 
  u.RollNumber = 183;
  u.CGPA = 10;
  strcpy(u.name, "YourName");
 
  printf("\nunion data:\n integeer: %d\n CGPA: %.2f\n name: %s\n", 
    u.RollNumber, u.CGPA, u.name);
 
  printf("\n Accessing one member at time:");
  printf("\n---------------------------------\n");
 
  printf("\nstructure data:");
  s.RollNumber = 240;
  printf("\nRollNumber: %d", s.RollNumber);

  s.CGPA = 120;
  printf("\nCGPA: %f", s.CGPA);

  strcpy(s.name, "Surname ");
  printf("\nname: %s\n", s.name);

  printf("\nunion data:");
  u.RollNumber = 240;
  printf("\nRollNumber: %d", u.RollNumber);

  u.CGPA = 120;
  printf("\nCGPA: %f", u.CGPA);

  strcpy(u.name, " Surname");
  printf("\nname: %s\n", u.name);

  //difference four
  printf("\nAltering a member value:\n");
  printf("\n---------------------------------\n");

  s.RollNumber = 1218;
  printf("structure data:\n RollNumber: %d\n CGPA: %.2f\n name: %s\n", 
    s.RollNumber, s.CGPA, s.name);
 
  u.RollNumber = 1218;
  printf("union data:\n RollNumber: %d\n CGPA: %.2f\n name: %s\n", 
    u.RollNumber, u.CGPA, u.name); 

  return 0;
}
