#include<stdio.h> 
#include <stdlib.h>   

struct date_t {
    unsigned short month;
    unsigned short day;
};

int get_month(struct date_t input);

enum month
{
JAN = 1 , FEB , MAR , APR , MAY , JUNE ,
JUL , AUG , SEPT , OCT , NOV , DEC
};


int main(void)
{
        struct date_t input;    

        printf("Enter the integer corresponding to the month\n");
        printf("or 20 to quit\n");
        scanf("%hu", &input.month);
        if(input.month == 20) {
                printf("buh bye bb\n");
                exit(EXIT_SUCCESS);
        }
        printf("Enter the integer corresponding to the date\n");
        scanf("%hu", &input.day);


        get_zodiac(input);

        return 0;
}


int get_zodiac(struct date_t input) 
{
    switch (input.month){
    case 1:
        printf("January %hu, ", input.day);
        break;
    case 2:
        printf("February %hu, ", input.day);
        break;
    case 3:
        printf("March %hu, ", input.day);
        break;
    case 4:
        printf("April %hu, ", input.day);
        break;
    case 5:
        printf("May %hu, ", input.day);
        break;
    case 6:
        printf("June %hu, ", input.day);
        break;
    case 7:
        printf("July %hu, ", input.day);
        break;
    case 8:
        printf("August %hu, ", input.day);
        break;
    case 9:
        printf("September %hu, ", input.day);        
        break;
    case 10:
        printf("October %hu, ", input.day);
        break;
    case 11:
        printf("November %hu, ", input.day);
        break;
    case 12:
        printf("December %hu, ", input.day);
        break;

    };

    if(input.month == JAN)
        if(input.day > 20)
            printf("Aquarius\n");
    if(input.month == FEB)
        if(input.day <= 19)
            printf("Aquarius\n");

    if(input.month == FEB)
        if(input.day > 21)
            printf("Pisces\n");
    if(input.month == MAR)
        if(input.day <= 20)
            printf("Pisces\n");

    if(input.month == MAR)
        if(input.day > 22)
            printf("Aries\n");
    if(input.month == APR)
        if(input.day <= 20)
            printf("Aries\n");

    if(input.month == APR)
        if(input.day > 20)
            printf("Tarus\n");
    if(input.month == MAY)
        if(input.day <= 21)
            printf("Tarus\n");

    if(input.month == MAY)
        if(input.day > 21)
            printf("Gemini\n");
    if(input.month == JUNE)
        if(input.day <= 21)
            printf("Gemini\n");

    if(input.month == JUNE)
        if(input.day > 21)
            printf("Cancer\n");
    if(input.month == JUL)
        if(input.day <= 22)
            printf("Cancer\n");

    if(input.month == JUL)
        if(input.day > 22)
            printf("Leo\n");
    if(input.month == AUG)
        if(input.day <= 23)
            printf("Leo\n");

        /*wikipedia chart has overlap on August 23rd. typo?*/
    if(input.month == AUG)
        if(input.day > 23)
            printf("Virgo\n");
    if(input.month == SEPT)
        if(input.day <= 23)
            printf("Virgo\n");

    if(input.month == SEPT)
        if(input.day > 23)
            printf("Libra\n");
    if(input.month == OCT)
        if(input.day <= 23)
            printf("Libra\n");

    if(input.month == OCT)
        if(input.day > 23)
            printf("Scorpio\n");
    if(input.month == NOV)
        if(input.day <= 22)
            printf("Scorpio\n");

    if(input.month == NOV)
        if(input.day > 22)
            printf("Sagittarius\n");
    if(input.month == DEC)
        if(input.day <= 21)
            printf("Sagittarius\n");

    if(input.month == DEC)
        if(input.day > 21)
            printf("Capricorn\n");
    if(input.month == JAN)
        if(input.day <= 20)
            printf("Capricorn\n");

    return 0;
}
