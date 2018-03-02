/**
 * @file sundays.c
 * @author Noah Cherry 
 * @date Spring 2015
 * @brief How many Sundays fell on the first of the month during the twentieth century?
 */

#include <stdio.h>

int is_leapyear(int year);
int count_sundays(int year);

int main(void)
{
    printf("the number of sundays is %d\n", count_sundays(1900));
    return 0;
}

/** checks if a given year is a leap year
 * @param year the given year
 * @return a true/yes false/no
 */
int is_leapyear(int year)
{
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/** counts sundays that occured on the first of the month
 * @param year the year to start evaluating through
 * @return the count of sundays
 */
int count_sundays(int year)
{
        int year_perm = year;
        int sundays = 0;
        int month = 0;
        int day_month;
        int i = 0;
        month = 1;
        sundays = 1;
     
        while (year <= 2000) {
                if (sundays == 0 && year > year_perm) {
                        i++;
                }
                switch (month) {
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                                day_month = 30;
                                break;
                        case 2:
                                if (is_leapyear(year))
                                        day_month = 29;
                                else
                                        day_month = 28;
                                        break;
                        default:
                                day_month = 31;
                }
                sundays = (sundays + day_month) % 7;
                month++;
                if (month > 12) {
                        month = 1;
                        year++;
                }
        }
        return i;
}