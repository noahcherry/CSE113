#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], size_t len)
{
	int i;

	for(i = 0; i < len; i++)
		printf(i == len - 1 ? "%d\n" : "%d ", a[i]);
        printf("\n");
			
}

/* pointer arthimetic version of print_array */
void print_parray(int *a, size_t len)
{
        int i;
        //size_t len = sizeof(*a)/ sizeof(int);
        for (i = 0; i < len; i ++)
                printf("%d ", *( a + i ));
        printf("\n\n");
			
}

/*
void inc_array(int a[], size_t len)
{
	int i;
 
	for(i = 0; i < len; i++)
		a[i]++; 
		
}
*/

/* pointer based version */
void inc_parray(int *a, size_t len)
{
 	int *p = a; 
        int i;
        for(i = 0; i < len; i++, (*a)++, a++)
                ; 
}

/* a = a + b */
void add_arrays(int *a, int *b, size_t len)
{
	int i;
	
	for(i = 0; i < len; i++) 
		a[i] += b[i];
	
}

/* pointer version of add_arrays a = a + b */
void add_parrays(int *a, int *b, size_t len)
{
        int i;
        for(i = 0; i < len; i++, a++, b++)
                *a += *b; 
	
}


int main() 
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	size_t len_a = sizeof(a)/sizeof(int);
	size_t len_b = sizeof(b)/sizeof(int);
	
	printf("a = ");
	print_array(a, len_a);
	//print_parray(a, len_a);

	printf("b = ");
	print_array(b, len_b);
	//print_parray(b, len_b);

	printf("after incrementing\na = ");
	//inc_array(a, len_a);
	// print_array(a, len_a);
	inc_parray(a, len_a);
	print_parray(a, len_a);

	if (len_a != len_b) 	/* assume arrays are of the same length */
		exit(EXIT_FAILURE);
	else
		//add_arrays(a, b, len_a);
		add_parrays(a, b, len_a);
	
	printf("a = a + b\na = ");
	print_array(a, len_a);
	/* print_parray(a, len_a); */
	printf("b remains unchanged\nb = ");
	print_array(b, len_b);
	/* print_parray(b, len_b); */

	return 0;
}
