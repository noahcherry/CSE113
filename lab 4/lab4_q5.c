#include <stdlib.h>   
#include<stdio.h> 

enum color
{
    RED = 1, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET
};

int get_color(int input);

int main(void)
{
    int input;    

    printf("Enter the integer corresponding to the color\n");
    printf("1.) Red\n");
    printf("2.) Orange\n");
    printf("3.) Yellow\n");
    printf("4.) Green\n");
    printf("5.) Blue\n");
    printf("6.) Indigo\n");
    printf("7.) Violet\n");
    printf("or 20 to quit\n");
    scanf("%d", &input);
    get_color(input);
        
    return 0;
}


int get_color(int input) 
{
    switch (input){
    case 1:
        printf("Red\n");
        break;
    case 2:
        printf("Orange\n");
        break;
    case 3:
        printf("Yellow\n");
        break;
    case 4:
        printf("Green\n");
        break;
    case 5:
        printf("Blue\n");
        break;
    case 6:
        printf("Indigo\n");
        break;
    case 7:
        printf("Violet\n");
        break;
    case 20:
        printf("buh bye bb\n");
        exit(EXIT_SUCCESS);
        break;
   };

    return 0;
}
