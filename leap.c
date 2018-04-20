// Find if input year is a leap year or not
#include <stdio.h>

int main()
{
  int year;

  printf("\nEnter a 4-digit year: ");
  scanf("%d", &year);

  if (year < 0)
  {
    printf("\nYear cannot be negative. Invalid year entered!\n");
    return -1;
  }
  else if (year <= 999 || year > 9999)
  {
	// This check needs to be improved
    printf("\nYear entered is not 4-digit long. Invalid year entered!\n");
    return 1;
  }

  // A year a leap year if it is divisible by 4 and
  // assume a century year is leap year if it is divisible by 400.
  if ((year % 4 == 0 && year % 100 != 0) ||
      (year % 400 == 0))
  {
    printf("\nYear %d is a leap year.\n", year);
  }
  else
  {
    printf("\nYear %d is NOT a leap year.\n", year);
  }

  return 0;
}
