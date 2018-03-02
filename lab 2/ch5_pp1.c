/**
 * @file ch5_pp1.c.c
 * @brief count digits in a number
 * 
 * @author Noah Cherry
 * @date Spring 2015
 */
#include <stdio.h>

int digit_count(int num);

int main(void)  
{
        int num;

        printf("Enter a number: ");
        scanf("%d", &num);

        printf("the number %d has %d digits\n", num, digit_count(num));

        return 0;
}
/** counts the places in a given number
 * @param num the given number
 * @return the number of digit places
 */
int digit_count(int num) 
{
        int count = 0;
        while(num != 0)
        {
                count++;
                num /= 10;
        }
        return count;
}