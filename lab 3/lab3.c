 /**
 * @file lab3.c
 * 
 * @author Scott Chadde + Noah Cherry
 *
 * @date 1/1/2013 , Spring 2015
 *
 * @brief a program that tests the functions in array.c
 *
 * @details 
 *  
 * @bugs none
 *
 * @todo none
 */

#include <stdio.h>

#include <stdio.h>
#include "array.h"
#define LT 10
#define LE 11
#define GT 12 
#define GE 13
#define EQ 14

int main(void)
{
	int a[] = {9, 7, 5, 3, 2, 77, 8, 12, 4, 5, 11};
        /*int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int c[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        int d[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int e[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int f[] = {5, 7, 8, 4, 3, 10, 1, 4, 4, 5};*/

	size_t size = sizeof(a)/sizeof(int);

	print_array(a, size);

	return 0;
}

void print_summary(size_t size)
{
    /*use %zu for printing size_t types*/
    printf("the array size = %zu\n", size);
    printf("the array maximum = %d\n", max);
    printf("the array minimum = %d\n", min);
    printf("the array midpoint = %d\n", midpoint);
    printf("the count less than the midpoint = %d\n", countlm);
    printf("the count greater then the midpoint = %d\n", countgm);
    printf("the sum of the list elements = %d\n", sum);
    printf("the average of the list elements = %d\n", average);
    printf("the median of the list = %d\n", median);
    printf("the count of evens in the list = %d\n", evens);
    printf("the count of odds = %d\n", odds);
    printf("the count of elements divisible by the min = %d\n", divisibles);
}


