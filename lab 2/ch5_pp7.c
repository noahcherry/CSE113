/**
 * @file ch5_pp7.c
 * @brief find min and max of four numbers
 * 
 * @author Noah Cherry
 * @date Spring 2015
 */
#include <stdio.h>

int find_max(int max, int b, int c, int d);
int find_min(int min, int b, int c, int d);

int main(void)  
{
        int first, second, third, fourth;

        printf("Enter four numbers: ");
        scanf("%d %d %d %d", &first, &second, &third, &fourth);

        printf("Largest %d\nSmallest: %d\n",find_max(first, second, third, fourth), find_min(first, second, third, fourth));

        return 0;
}
/** finds max of four seperate numbers
 * @param max first number
 * @param b second number
 * @param c third number
 * @param d fourth number
 * @return max of four numbers
 */
int find_max(int max, int b, int c, int d)
{
        if(max < b)
                max = b;
        if(max < c)
                max = c;
        if(max < d)
                max = d;
        return max;
                
}

/** finds min of four seperate numbers
 * @param min first number
 * @param b second number
 * @param c third number
 * @param d fourth number
 * @return min of four numbers
 */
int find_min(int min, int b, int c, int d)
{
        if(min > b)
                min = b;
        if(min > c)
                min = c;
        if(min > d)
                min = d;
        return min;                
}