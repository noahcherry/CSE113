/**
 * @file array.c
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief Functions for fundamental array algorithms. 
 *
 * @details The functions implemented include basic counting, 
 * summing, searching, and basic statistical methods (average,
 * median, the max, the min). Sorting is implemented via
 * bubble sort, a not very efficient sort.
 *  
 * @bugs none
 *
 * @todo implement floating point versions of the functions
 */


#include "array.h"
#include <stdio.h>


/** prints out the elements of an array, one element per line
 * @param a[] the array to print
 * @size the size or length of the array
 */
void print_array(int a[], size_t size)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("a[%d] = %d\n", i, a[i]);

}

/** finds the maximum value in an array
 * @param a[] array for evaluation
 * @param size size of the array
 * @return maximum of the array
 */
int find_max(int a[], size_t size) 
{
        int max = a[0];
        int i;
        for (i = 0; i < size - 1; i++) {
                if (a[i + 1] > max)
                        max = a[i + 1];
        }
        return max;
}

/** finds the minium value in an array
 * @param a[] array for evaluation
 * @param size size of the array
 * @return minimum of the array
 */
int find_min(size_t size, int a[]) 
{
        int min = a[0];
        int i;
        for (i = 0; i < size - 1; i++) {
                if (a[i + 1] < min)
                        min = a[i + 1];
        }
        return min;
}

/** finds the value halfway between the max and min
 * @param min the lowest value
 * @param max the highest value
 * @return the midpoint
 */
int midpoint(int min, int max)
{
        return (min + max) / 2;
}

/** count elements Greater/Less Than or Equal to a specific value
 * @param a[] array containing elements for evaluation
 * @param size size of the array a[]
 * @param type the type of comparison to preform
 * @param x the value to compare against
 * @return count of elements
 */
int get_count(int a[], size_t size, int type, int x) 
{
        int i = 0;
        int count = 0;

        switch (type) {
        case LT:
                for (i = 0; i < size; i++) {
                        if (a[i] < x)
                                count += 1;
                }
                printf("Less than %d: %d\n", x, count);
                break;
        case LE:
                for (i = 0; i < size; i++) {
                        if (a[i] <= x)
                                count += 1;
                }
                printf("Less then or equal to %d: %d\n", x, count);
                break;
        case GT:
                for (i = 0; i < size; i++) {
                        if (a[i] > x)
                                count += 1;
                }
                printf("Greater than %d: %d\n", x, count);
                break;
        case GE:
                for (i = 0; i < size; i++) {
            if (a[i] >= x)
                count += 1;
                }
                printf("Greater than or equal to %d: %d\n", x, count);
                break;
        case EQ:
                for (i = 0; i < size; i++) {
                        if (a[i] == x)
                                count += 1;
                }
                printf("Equal to %d: %d\n", x, count);
                break;
        default:
                printf("bb pls.");
        }
        return count;
}

/** sums the elements in an array
 * @param a[] array containing elemnts to evaluate
 * @param size size of array a[]
 * @return sum of elements
 */
int sum(int a[], size_t size)
{
        int i;
        int sum = 0;
        for(i = 0; i < size; i++) {
                sum += a[i];
        }
        return sum;
}

/** averages elements of an array
 * @param a[] array containing elements to evaluate
 * @param size size of array a[]
 * @return average of array
 */
int average(int a[], size_t size)
{
        return sum(a, size) / size;    
}

/** sorts an array with the "bubble sort" algorithem
 * @param a[] array containing elements for evaluation
 * @param sizesize of array a[]
 * @return 0
 */
int bubble(int a[], size_t size) 
{
        int i = 0;
        int j = 0;
        for(i = 0; i < size; i++) {
                for(j = 0; j < size - 1 - i; j++) {
                        if (a[j] > a[j + 1]) {
                                int temp = a[j + 1];
                                a[j + 1] = a[j];
                                a[j] = temp;
                        }
                }
        }
        return 0;
}

/** sorts an array with the "insertion sort" algorithem
 * @param a[] array containing elements for evaluation
 * @param size size of the array a[]
 * @return 0
 */
int insertion_sort(int a[], size_t size)
{
        int i = 0;
        int j = 0;
        int index;
        for(i = 0; i < size; i++) {
                index = i;
                for(j = 0; j < size; j++) {
                        if(a[i] > a[j])
                                index = j;
                }
                int temp = a[i];
                a[i] = a[index];
                a[index] = temp;
        }
        return 0;
}

/** reverses an array / flips the order of elements in an array
 * @param a[] array containing elements for evaluation 
 * @param size size of array a[]
 * @return N/A
 */
void reverse(int a[], size_t size)
{
        int i = 0;
        for (i = 0; i < size / 2; i++) {
                int temp = a[i];
                a[i] = a[size-i];
                a[size-1] = temp;
        }
}

/** finds the median of an array
 * @param a[] array containing elements for evaluation
 * @param size size of array a[]
 * @return median of array a[]
 */
int median(int a[], size_t size) 
{
        int med = 0;
        if (size % 2 == 0) 
                return med = ( a[size / 2] + a[(size / 2) + 1 ]) / 2;
        else
                return med = a[(size + 1) / 2];
}

/** counts even elements in an array
 * @param a[] array with elements for evaluation
 * @param size size of array a[]
 * @return count of even numbers
 */
int even_count(int a[], size_t size)
{
        int i = 0;
        int count = 0;
        for( i = 0; i < size; i++) {
                if( a[i] % 2 == 0 ) 
                        count +=1;
        }
        return count;
}

/** counts odd elements in an array 
 * @param a[] array with elements for evaluation
 * @param size size of array a[]
 * @return count of odd elements
 */
int odd_count(int a[], size_t size)
{
        int i = 0;
        int count = 0;
        for( i = 0; i < size; i++) {
                if( a[i] % 2 == 1 ) 
                count +=1;
        }
        return count;
}

/** counts elements divisible by a certain number
 * @param a[] array with elements for evaluation
 * @param size size of arrya a[]
 * @param x divisor for comparison agains array elements
 * @return 
 */
int divisible_count(int a[], size_t size, int x)
{
        int i = 0;
        int count = 0;
        for( i = 0; i < size; i++) {
                if( a[i] % x == 0 ) 
                        count +=1;
        }
        return count;
}