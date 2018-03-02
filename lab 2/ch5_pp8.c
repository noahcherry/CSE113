/**
 * @file ch5_pp8.c
 * @brief given a list of departure/arival times, finds closest one to user input
 * 
 * @author Noah Cherry
 * @date Spring 2015
 */
#include <stdio.h>

int digit_count(int num);
int closest_element(int time, int a[]);

int main(void)  
{
        int departure[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
        int arrival[] = {616, 712, 811, 900, 968, 1075, 1280,1438};

        int temptime;
        int time;

        printf("Enter a 24-hour time: ");
        scanf("%d:%d", &temptime, &time);

        time = (temptime * 60) + time;

        int element = closest_element(time, departure);

        printf("closest departure time is ");
        if(departure[element] > 780)
                printf("%d:%02d p.m.", (departure[element] / 60) / 12, departure[element] % 60);
        else if(departure[element] > 720)
                printf("%d:%02d p.m.", departure[element] / 60, departure[element] % 60);
        else 
                printf("%d:%02d a.m.", departure[element] / 60, departure[element] % 60);
        printf(", arriving at ");
        if(arrival[element] > 780)
                printf("%d:%02d p.m.\n", (arrival[element] / 60) / 12, arrival[element] % 60);
        else if(arrival[element] > 720)
                printf("%d:%02d p.m.\n", arrival[element] / 60, arrival[element] % 60);
        else 
                printf("%d:%02d a.m.\n", arrival[element] / 60, arrival[element] % 60);


        return 0;
}
/** prints number for tens place
 * @param time item to be compared against array
 * @param a[] array of departure times
 * @return elemnt number of closest element
 */
int closest_element(int time, int a[])
{
        int i;
        for(i = 0; time > a[i]; i++)
                ;
        if(a[i] - time < time - a[i - 1])
                return i;
        else
                return i - 1;


}