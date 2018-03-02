#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include<stdio.h> 
#include <stdlib.h>  

struct zombie{
        char dead; /*y if dead n if alive*/
        enum {MONDAY = 1, TUESADY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} day;
        int toes;
        float blood;
        int hour;
        int min;    
        int sec;
};

struct zombie get_time(struct zombie encounter);
int get_toes();
float get_blood();
int print_data(struct zombie log[]);

#endif
