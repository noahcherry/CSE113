/**
 * @file ch5_pp11.c
 * @brief print two digit number using letters/english words
 * 
 * @author Noah Cherry
 * @date Spring 2015
 */

#include <stdio.h>

void tens(int num);
void ones(int num);
void special_cases(int num);

int main(void)  
{
        int num;

        printf("Enter a two digit number: ");
        scanf("%d", &num);

        printf("you entered the number ");
        tens(num);
        ones(num);
        special_cases(num);

        return 0;
}
/** prints number for tens place
 * @param num number for evaluation
 * @return void
 */
void tens(int num)
{
        int ten = num / 10;
        switch (ten) {
                case 2:
                        printf("twenty");
                        break;
                case 3:
                        printf("thirty");
                        break;
                case 4:
                        printf("fourty");
                        break;
                case 5:
                        printf("fifty");
                        break;
                case 6:
                        printf("sixty");
                        break;
                case 7:
                        printf("seventy");
                        break;
                case 8:
                        printf("eighty");
                        break;
                case 9:
                        printf("ninty");
                        break;
        }
}

/** prints number for ones place
 * @param num number for evaluation
 * @return void
 */
void ones(int num)
{
        int ten = num / 10;
        int one = num - (ten * 10);
        if(ten != 0 && ten != 1)
                printf("-");
        if(ten != 1) {
                switch (one) {
                        case 1:
                                printf("one.\n");
                                break;
                        case 2:
                                printf("two.\n");
                                break;
                        case 3:
                                printf("three.\n");
                                break;
                        case 4:
                                printf("four.\n");
                                break;
                        case 5:
                                printf("five.\n");
                                break;
                        case 6:
                                printf("six.\n");
                                break;
                        case 7:
                                printf("seven.\n");
                                break;
                        case 8:
                                printf("eight.\n");
                                break;
                        case 9:
                                printf("nine.\n");
                                break;
                        case 0:
                                printf(".\n");
                                break;
                }
        }
}

/** prints numbers from 11 to 19
 * @param num number for evaluation
 * @return void
 */
void special_cases(int num)
{
        int ten = num / 10;
        int one = num - (ten * 10);
        if(ten == 1) {
                switch (one) {
                        case 1:
                                printf("eleven.\n");
                                break;
                        case 2:
                                printf("twelve.\n");
                                break;
                        case 3:
                                printf("thirteen.\n");
                                break;
                        case 4:
                                printf("fourteen.\n");
                                break;
                        case 5:
                                printf("fifteen.\n");
                                break;
                        case 6:
                                printf("sixteen.\n");
                                break;
                        case 7:
                                printf("seventeen.\n");
                                break;
                        case 8:
                                printf("eighteen.\n");
                                break;
                        case 9:
                                printf("nineteen.\n");
                                break;
                        case 0:
                                printf("ten.\n");
                                break;
                }
        }
}
