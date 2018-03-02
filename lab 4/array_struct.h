#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */
	
};

void fill_array(struct data_t data[], int index, char id, int years, int inches);
int find_min_age(struct data_t data[]);
int find_min_height(struct data_t data[]);
int find_max_age(struct data_t data[]);
int find_max_height(struct data_t data[]);
float average_age(struct data_t data[]);
float average_height(struct data_t data[]);
void print_structure(struct data_t data[], int index);

#endif
