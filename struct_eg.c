#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SID 13
#define MAX_NAME 64
#define MAX_EMAILID 32
#define MAX_DOB 11
#define MAX_DOMAIN_SUFFIX 16
#define MAX_STATE 32
#define MAX_CATEGORY 5

const char domain_suffix[MAX_DOMAIN_SUFFIX] = "@iitjammu.ac.in";

typedef struct date
{
  unsigned short day;	// DD
  unsigned short month;	// MM
  unsigned int year;	// YYYY
} DATE;

// Student record
typedef struct student
{
  char sid[MAX_SID];		// e.g. 2017KUCP1001
  char name[MAX_NAME];
  char emailid[MAX_EMAILID];	// e.g. 2017KUCP1001@iiitjammu.ac.in
  char gender;			// M = Male / F = Female
  char dob[MAX_DOB];		// DD-MM-YYYY e.g. 01-01-2001

  //DATE date_enrolled;

  enum student_status
  {
    ss_Active,
    ss_Passed_Out,
    ss_Inactive
  } status;

  // student's state of domicile
  char state[MAX_STATE];

  // student's admission category: SC/ST/PH/OBC/Open
  char category[MAX_CATEGORY];

  // student's family income group: 
  // IG_LT1 -> SC/ST/PH
  // IG_LT1 -> family income below 1 lac
  // IG_LT5 -> family income above 1 lac and below 5 lac
  // IG_GT5 -> family income above 5 lac
  enum income_group
  {
    ig_SC,
    ig_ST,
    ig_PH,
    ig_IG_LT1,
    ig_IG_LT5,
    ig_IG_GT5
  } family_income_group;


} STUDENT;

int main()
{
  printf("\n\tIIT Jammu student records: entry\n");

  int n = 0;
  unsigned int i = 0;
  char enter;

  printf("\nHow many student records are there? ");
  scanf("%d", &n);

  // Check input for student record count
  if (n <= 0)
  {
    printf("\nInvalid number!\n");
    return -1;
  }

  // Declare n array of pointers to structure student
  STUDENT *s[n];

  for (i = 0; i < n; i++)
  {
    // Allocate memory to individual structures
    s[i] = (STUDENT *) malloc(sizeof(STUDENT));

    // Check for memory allocation errors
    if (NULL == s[i])
    {
      printf("\nMemory allocation error!\n");
      return -2;
    }
  }

  enter = getchar();

  // Read student record details
  for (i = 0; i < n; i++)
  {
    printf("\nDetails of student[%d]\n", i+1);

    printf("\nEnter student id: ");
    scanf("%[^\n]s", s[i]->sid);
    enter = getchar();

    printf("\nEnter student's name: ");
    scanf("%[^\n]s", s[i]->name);
    enter = getchar();

    // Create email id from student id and domain_suffix
    strncat(s[i]->emailid, s[i]->sid, strlen(s[i]->sid));
    strncat(s[i]->emailid, domain_suffix, strlen(domain_suffix));

    printf("\nEnter student's gender [M/F]: ");
    scanf(" %c", &s[i]->gender);
    enter = getchar();

    printf("\nEnter student's DOB: ");
    scanf("%[^\n]s", s[i]->dob);
    enter = getchar();

    // Compute status from enrollment date
    s[i]->status = ss_Active;


  } // student record entry ends here

  printf("\n\tIIT Jammu student records: display\n");

  for (i = 0; i < n; i++)
  {
    printf("\nDetails of student[%d]\n", i+1);

    printf("\tstudent id: %s\n", s[i]->sid);
    printf("\tstudent's name: %s\n", s[i]->name);
    printf("\tstudent's email id: %s\n", s[i]->emailid);
    printf("\tstudent's gender: %c\n", s[i]->gender);
    printf("\tstudent's DOB: %s\n", s[i]->dob);

    switch (s[i]->status)
    {
      case ss_Active:
        printf("\tstudent status: Active \n");
        break;

      case ss_Passed_Out:
        printf("\tstudent status: Active \n");
        break;

      case ss_Inactive:
        printf("\tstudent status: Active \n");
        break;

      default:
        printf("Invalid status!\n");
    }

  } // student record display ends here

  // Free memory
  for (i = 0; i < n; i++)
  {
    free(s[i]);
    s[i] = NULL;
  }

  return 0;
}
