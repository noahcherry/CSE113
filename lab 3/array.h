/**
 * @file array.h
 * 
 * @author Scott Chadde
 *
 * @date 1/1/2013
 *  
 * Assignment: Lab 3 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo add floating point versions of the functions
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		/* for size_t declaration */
struct summary_t {
    size_t size;
    int max;
    int min;
    int mid;
    int sums;
    int avg;
    int med;
    int evens;
    int odds;
    int divisibles;
    int countgm;
    int countlm;
    int linmid;
};

/* prints out the elements of an array, one element per line*/
void print_array(int a[], size_t size);

void get_summary(struct summary_t summary, int a[], size_t size);
void print_summary(struct summary_t summary);
//void print_summary(size_t size, int max, int min, int midpoint, int countgm, int countlm, int linear, int sum, int average, int median, int evens, int odds, int divisibles);

int find_max(int a[], size_t size);
int find_min(int a[], size_t size);
int midpoint(int a[], size_t size);
int get_count(int a[], size_t size, int type, int x);
int linear_search(int a[], size_t size, int x);
int sum_elements(int a[], size_t size);
int average_elements(int sum, size_t size);
int bubble_sort(int a[], size_t size);
int insertion_sort(int a[], size_t size);
void reverse(int a[], size_t size);
int median(int a[], size_t size);
int even_count( int a[], size_t size);
int odd_count( int a[], size_t size);
int divisible_count( int a[], size_t size, int x);

#endif
