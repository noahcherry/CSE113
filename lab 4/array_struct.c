#include "array_struct.h"
#include <stdio.h>


int main(void)
{

	struct data_t data[SIZE];

	/* data initialization calls */
	fill_array(data, 0, 'A', 23, 74);
	fill_array(data, 1, 'B', 22, 64);
	fill_array(data, 2, 'C', 19, 68);
	fill_array(data, 3, 'D', 20, 76);
	fill_array(data, 4, 'E', 22, 62);

        printf("min age subject:\n");
        print_structure(data, find_min_age(data));

        printf("max age aubject:\n");
        print_structure(data, find_max_age(data));

        printf("min height subject:\n");
        print_structure(data, find_min_height(data));

        printf("max height subject:\n");
        print_structure(data, find_max_height(data));

        printf("average age of subjects: %f\n", average_age(data));

        printf("average height of subjects: %f\n", average_height(data));

	return 0;
}

/** creates a structure element and adds it to an array
 * @param data[] array to be modified
 * @param index elemnt of data[] to be modified
 * @param id data to be added to data[index]
 * @param years data to be added to data[index]
 * @param inches data to be added to data[index]
 */
void fill_array(struct data_t data[], int index, char id, int years, int inches)
{
        data[index].age = years;
        data[index].height = inches;
        data[index].subject = id;
}

/** compares sturctures and finds minimum age element
 * @param data[] array containing elemnts for comparison
 * @return index of the min age
 */
int find_min_age(struct data_t data[])
{
        int i;
        int min = 100;
        int index = 0;
        for(i = 0; i < SIZE; i++) {
                if(data[i].age < min) {
                        min = data[i].age;
                        index = i;
                }
        }
        return index;
}

/** compares sturctures and finds minimum age element
 * @param data[] array containing elemnts for comparison
 * @return index of the min age
 */
int find_min_height(struct data_t data[])
{
        int i;
        int min = 100;
        int index = 0;
        for(i = 0; i < SIZE; i++) {
                if(data[i].height < min) {
                        min = data[i].height;
                        index = i;
                }
        }
        return index;
}

/** compares sturctures and finds maximum age element
 * @param data[] array containing elemnts for comparison
 * @return index of the max age
 */
int find_max_age(struct data_t data[])
{
        int i;
        int max = 0;
        int index = 0;
        for(i = 0; i < SIZE; i++) {
                if(data[i].age > max) {
                        max = data[i].age;
                        index = i;
                }
        }
        return index;
}

/** compares sturctures and finds maximum height element
 * @param data[] array containing elemnts for comparison
 * @return index of the max height
 */
int find_max_height(struct data_t data[])
{
        int i;
        int max = 0;
        int index = 0;
        for(i = 0; i < SIZE; i++) {
                if(data[i].height > max) {
                        max = data[i].height;
                        index = i;
                }
        }
        return index;
}

/** compares sturctures and finds average age 
 * @param data[] array containing elemnts for comparison
 * @return average age
 */
float average_age(struct data_t data[])
{
        int i;
        float average;
        for(i = 0; i < SIZE; i++)
                average += data[i].age;
        
        return average / SIZE;
}

/** compares sturctures and finds average height 
 * @param data[] array containing elemnts for comparison
 * @return average height
 */
float average_height(struct data_t data[])
{
        int i;
        float average = 0;
        for(i = 0; i < SIZE; i++)
                average += (float) data[i].height;
        return average / SIZE;
}

/** prints structure data_t
 * @param data[] array containing elemnts for printing
 * @param index index of elemnt to be printed
 */
void print_structure(struct data_t data[], int index)
{
        printf("\tsubject: %c\n\tage: %d\n\theight: %d\n",data[index].subject, data[index].age, data[index].height);
}