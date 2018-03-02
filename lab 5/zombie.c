/**
 * @file zombie.c
 * @author Noah Cherry
 * @date Spring 2015
 * @brief contains funtions to be called by lab5.c
 */

#include<stdio.h> 
#include <stdlib.h>
#include "zombie.h"

/** fills time-related elements in struct zombie
 * @param encounter structure to be filled
 * @return filled structure
 */
struct zombie get_time(struct zombie encounter)
{
        char buf[1024];
        int day;
        int hour;
        int min;
        int sec;

        printf("Please choose the day this zombie was encountered:\n");
        printf("1) Monday\n2) Tuesday\n3) Wednesday\n4) Thursday\n5) Friday\n6) Saturday\n7) Sunday\n>> ");

        fgets(buf, 1024, stdin);
        sscanf(buf, "%d", &day);
        encounter.day = day;

        printf("\nEnter the time when this zombie was encountered.\n");
        printf("Seperate hours, minutes, and seconds by  colons\n");
        printf("HH:MM:SS\n>> ");

        fgets(buf, 1024, stdin);
        sscanf(buf, "%d:%d:%d", &hour, &min, &sec);
        encounter.hour = hour;
        encounter.min = min;
        encounter.sec = sec;

        return encounter;
}

/** asks user to provide a number to represent toes on a zombie
 * @return integer representing toes
 */
int get_toes()
{
        char buf[1024];
        int toes;

        printf("\nPlease enter the number of toes the zombie had\n>> ");
        
        fgets(buf, 1024, stdin);
        sscanf(buf, "%d", &toes);

        return toes;
}

/** asks user to provide a float-type number to represent mL of blood
 * @return a float representing zombie blood
 */
float get_blood()
{
        char buf[1024];
        float blood;

        printf("\nPlease enter the amount of blood that oozed from its body after you killed it(in mL)\n>> ");

        fgets(buf, 1024, stdin);
        sscanf(buf, "%f", &blood);
    
        return blood;
}

/** prints all recorded zombie encounters
 * @param log[] contains all encounters and related information
 * @param count amount of encounters recorded
 */
int print_data(struct zombie log[])
{
        int i = 0;

        for(i = 0; i < 5; i++) {
                if (log[i].dead == 'Y' || log[i].dead == 'y') {
                        printf("\n%d.) This zombie was found dead.\nIt had %d toes.\n", i + 1, log[i].toes);
                }
                else if (log[i].dead == 'N' || log[i].dead == 'n') {
                        printf("\n%d.) This zombie was found ALIVE!\nIt was drained of %fmL of blood once killed.\n>>", i + 1, log[i].blood);
                }
                else
                        return 0;
                switch (log[i].day)
                {
                        case 1:
                                printf("This zombie was sighted on Sunday");
                                break;
                        case 2:
                                printf("This zombie was sighted on Monday");
                                break;
                        case 3:
                                printf("This zombie was sighted on Tuesday");
                                break;
                        case 4:
                                printf("This zombie was sighted on Wednesday");
                                break;
                        case 5:
                                printf("This zombie was sighted on Thursday");
                                break;
                        case 6:
                                printf("This zombie was sighted on Friday");
                                break;
                        case 7:
                                printf("This zombie was sighted on Saturday");
                                break;
                    }

                        printf(" at %02d:%02d:%02d\n\n", log[i].hour, log[i].min, log[i].sec);
        }
}