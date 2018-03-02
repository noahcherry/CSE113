#include <stdio.h>
#include <stdlib.h>


#define MALLOC_FAILED -99
#define LEN 100

/** finds the minium value in an array
 * @param a array for evaluation
 * @param size size of the array
 * @return minimum of the array
 */
double find_min(size_t size, double *a) 
{
        double min = *a;
        a++;
        int i = 0;
        while(i < size - 1) {
                if (*a < min)
                        min = *a;
                a++;
                i++;
        }
        return min;
}

/** finds the maximum value in an array
 * @param a array for evaluation
 * @param size size of the array
 * @return maximum of the array
 */
double find_max(size_t size, double *a) 
{
        double max = *a;
        a++;
        int i = 0;
        while(i < size - 1) {
                if (*a > max)
                        max = *a;
                a++;
                i++;
        }
        return max;
}

/** sums the elements in an array
 * @param a array containing elemnts to evaluate
 * @param size size of array a
 * @return sum of elements
 */
double sum(size_t size, double *a)
{
        double sum = 0;
        int i = 0;
        while(i < size) {
                sum += *a;
                a++;
                i++;
        }
        return sum;
}

/** averages elements of an array
 * @param a array containing elements to evaluate
 * @param size size of array a
 * @return average of array
 */
float average(size_t size, double *a)
{
        return (float)sum(size, a) / (float)size;    
}

/** finds the median of an array
 * @param a array containing elements for evaluation
 * @param size size of array a
 * @return median of array a
 */
double median(double *a, size_t size) 
{
        int med = 0;
        int i;
        if (size % 2 == 0) {
                for(i = 0; i < (size / 2); i++)
                        a++;
                return (float)(*a + (--(*a))) / (float)2.0;
        }
        else {
                for(i = 0; i < (size / 2); i++)
                        a++;
                return *a;
        }
}


int main(void)
{
	int size;
	double *d;
	char buf[LEN];
	int i = 0;


	printf("Enter a size for your array: ");
	
	fgets(buf, LEN, stdin);
	sscanf(buf, "%d", &size);
	
	d = malloc(size * sizeof(double));
	
	if (d == NULL) {
		printf("malloc failed. goodbye...\n");
		exit(MALLOC_FAILED);
	}
		
	/* initialize elements to zero */
	for(i = 0; i < size; i++)
		*(d + i) = 0.0;

	i = 0; 			/* reset i */

	while (i < size) {

		printf("Enter a value: ");

		/* Ctrl+d pressed or some other error, fgets returns NULL*/
		if (fgets(buf, LEN, stdin) == NULL) {
			printf("\n");
			break;
		}

		sscanf(buf, "%lf", &d[i++]);
	}
	

	for (i = 0; i < size; ++i)
		printf("%lf\n", *(d + i));

        printf("\n min = %f \n", find_min(size, d));
        printf("\n max = %f \n", find_max(size, d));
        printf("\n average = %f \n", average(size, d));
        printf("\n median = %f \n", median(d, size));

	return 0;

}
