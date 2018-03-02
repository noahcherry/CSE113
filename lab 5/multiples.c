/**
 * @file multiples.c
 * @author Noah Cherry 
 * @date Spring 2015
 * @brief Problem 1 from Project Euler
 */

#include <stdio.h>

int main()
{
    int cap = 1000;
    int sum = 0;
    int i;

    for(i = 0; i < cap; i++) {
        if(i % 3 == 0)
            sum += i;
        /*use else-if to avoid "double summing" numbers like 15 or 30*/
        else if(i % 5 == 0)
            sum += i;
    };
    printf("%d\n", sum);
    return 0;
}