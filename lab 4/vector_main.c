#include <stdio.h> 
#include <time.h>
#include "vector.h"

int main(void) 
{ 
        int x = 50;
        int num = 5; 
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
        int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
        int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
        int a4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
        int a5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 3}; 
        int a6[] = {1, 2, 3, 4, 5}; 
        int a7[] = {1, 2, 3, 4, 5}; 
        int a8[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

        int b3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
        int b4[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; 
        int b5[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; 
        int b6[] = {6, 7, 8, 9, 10}; 

        int c4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};    
        int c5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
        int c6[] = {0, 0, 0, 0, 0}; 

        size_t size = sizeof(a)/sizeof(int);

        srandom(time(NULL));

        multiply_array(a, num, size); 
        second_problem(a2, num, size);
        third_problem(a3, b3, size); 
        fourth_problem(a4, b4, c4, size); 
        fifth_problem(a5, b5, c5, size); 
        sixth_problem(a6, b6, c6, size = sizeof(a6)/sizeof(int)); 
        seventh_problem(a7, size = sizeof(a7)/sizeof(int));
        eigth_problem(a8, x);

        return 0;
} 