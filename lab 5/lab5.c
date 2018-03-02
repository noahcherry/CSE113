#include "zombie.h"
/**
 * @file lab5.c
 * @author Noah Cherry 
 * @date Spring 2015
 * @brief contains menu logic for the zombie lab
 */
#include <stdlib.h>
#include "zombie.h"

int main(void) 
{ 
        int count;
        char buff[1024]; 
        char buff2[1024];
        char dead;
        int choice;
        struct zombie log[5];   

        while (1) {

                printf("1) Enter new zombie information\n2) Display zombie information\n3) Return to fighting zombies (exit)\n");
                fgets(buff, 1024, stdin);
                sscanf(buff, "%d", &choice);
                if (choice == 3) {
                        printf("Stay alert! Keep a watch out for zombies!");
                        printf("\n\nGOODBYE and GOOD LUCK!\n");
                        exit(EXIT_SUCCESS);
                }
                else if (choice == 2)
                        print_data(log);
                else if (choice == 1) {
                        printf("\nWas the zombie found dead? Y or N\n>>");
                        fgets(buff2, 1024, stdin);
                        sscanf(buff2, "%c", &log[count].dead);
                        if (log[count].dead == 'Y' || log[count].dead == 'y')
                                log[count].toes = get_toes();
                        else if (log[count].dead == 'N' || log[count].dead == 'n')
                                log[count].blood = get_blood();
                        log[count] = get_time(log[count]);
                        count++; 
                }
                /*makes array building circular, 6th entry restarts at log[0]*/
                if (count == 5)
                        count = 0;    
        }
        return 0;
}