#include <stdio.h>

static char daytab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31},
                             {31, 29, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31}};

int day_of_year(int year, int month, int day) {
  int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  char *p = daytab[leap];

  for (int i = 0; i < month - 1; i++) {
    day += *(p + i);
  }

  return day;
}

void month_day(int year, int yearday, int *month, int *day) {
  int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  char *p = daytab[leap];
  int i = 0;
  for (i = 0; yearday > daytab[leap][i]; i++) {
    yearday -= *(p + i);
  }
  *month = i + 1;
  *day = yearday;
}

char *month_name(int n) {
  static char *name[] = {"Illegal Month", "January",   "Februrary", "March",
                         "April",         "May",       "June",      "July",
                         "August",        "September", "October",   "November",
                         "December"};

  if (n < 1 || n > 12)
    return name[0];
  return name[n];
}

int main(void) {
  // Test day_of_year function
  printf("Testing day_of_year:\n");
  printf("Jan 1, 2024: %d (expected: 1)\n", day_of_year(2024, 1, 1));
  printf("Feb 1, 2024: %d (expected: 32)\n", day_of_year(2024, 2, 1));
  printf("Feb 29, 2024 (leap): %d (expected: 60)\n", day_of_year(2024, 2, 29));
  printf("Mar 1, 2024: %d (expected: 61)\n", day_of_year(2024, 3, 1));
  printf("Dec 31, 2024 (leap): %d (expected: 366)\n",
         day_of_year(2024, 12, 31));
  printf("Dec 31, 2023 (non-leap): %d (expected: 365)\n",
         day_of_year(2023, 12, 31));
  printf("Jul 4, 2023: %d (expected: 185)\n", day_of_year(2023, 7, 4));

  printf("\nTesting month_day:\n");
  int month, day;

  month_day(2024, 1, &month, &day);
  printf("Day 1 of 2024: Month %d, Day %d (expected: Month 1, Day 1)\n", month,
         day);

  month_day(2024, 32, &month, &day);
  printf("Day 32 of 2024: Month %d, Day %d (expected: Month 2, Day 1)\n", month,
         day);

  month_day(2024, 60, &month, &day);
  printf("Day 60 of 2024: Month %d, Day %d (expected: Month 2, Day 29)\n",
         month, day);

  month_day(2024, 61, &month, &day);
  printf("Day 61 of 2024: Month %d, Day %d (expected: Month 3, Day 1)\n", month,
         day);

  month_day(2024, 366, &month, &day);
  printf("Day 366 of 2024: Month %d, Day %d (expected: Month 12, Day 31)\n",
         month, day);

  month_day(2023, 365, &month, &day);
  printf("Day 365 of 2023: Month %d, Day %d (expected: Month 12, Day 31)\n",
         month, day);

  month_day(2023, 185, &month, &day);
  printf("Day 185 of 2023: Month %d, Day %d (expected: Month 7, Day 4)\n",
         month, day);

  printf("\nTesting month_name:\n");
  printf("Month 1: %s (expected: January)\n", month_name(1));
  printf("Month 6: %s (expected: June)\n", month_name(6));
  printf("Month 12: %s (expected: December)\n", month_name(12));
  printf("Month 0 (invalid): %s (expected: Illegal Month)\n", month_name(0));
  printf("Month 13 (invalid): %s (expected: Illegal Month)\n", month_name(13));

  printf("\nTesting edge cases:\n");

  // Leap year edge cases
  printf("Feb 28, 2024 (leap): %d (expected: 59)\n", day_of_year(2024, 2, 28));
  printf("Feb 28, 2023 (non-leap): %d (expected: 59)\n",
         day_of_year(2023, 2, 28));

  // Century year leap year rules
  printf("Dec 31, 2000 (leap century): %d (expected: 366)\n",
         day_of_year(2000, 12, 31));
  printf("Dec 31, 1900 (non-leap century): %d (expected: 365)\n",
         day_of_year(1900, 12, 31));

  // Month boundaries
  month_day(2024, 31, &month, &day);
  printf("Day 31 of 2024: Month %d, Day %d (expected: Month 1, Day 31)\n",
         month, day);

  month_day(2023, 59, &month, &day);
  printf("Day 59 of 2023: Month %d, Day %d (expected: Month 2, Day 28)\n",
         month, day);

  month_day(2023, 60, &month, &day);
  printf("Day 60 of 2023: Month %d, Day %d (expected: Month 3, Day 1)\n", month,
         day);

  return 0;
}