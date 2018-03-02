/**
 * @file difference.c
 * @author Noah Cherry 
 * @date Spring 2015
 * @brief Problem 6 from Project Euler
 */

#include <stdio.h>

int main()
{
        int sum = 0; /*sum of the squares*/
        int squared = 0; /*square of the sum*/
        int num = 100; /*evaluate 1 through this variable*/
        int i;

        /*could start at i = 0 but that's just wasting processes, like what would be the point?*/
        for(i = 1; i <= num; sum += (i * i), squared += i, i++)
                ;
        squared = squared * squared;
        printf("sum of squares: %d\nsquare of sum: %d\ndifference: %d\n", sum, squared, (squared - sum));
        
        return 0;
}