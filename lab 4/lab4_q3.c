#include "stdio.h"
#include "stdlib.h"  
#include "math.h" 

struct point_t {
        float x;
        float y;
};

float euclid(struct point_t one, struct point_t two);
float manhattan(struct point_t one, struct point_t two);

int main(void)
{
        struct point_t one;
        struct point_t two;
        printf("enter first point : x y\n");
        scanf("%f %f", &one.x, &one.y);
        printf("enter second point : x y\n");
        scanf("%f %f", &two.x, &two.y);
        printf("euclidian: %f\n", euclid(one, two));
        printf("manhattan: %f\n", manhattan(one, two));
        return 0;
}

float euclid(struct point_t one, struct point_t two)
{
        return (sqrt(pow(one.x - two.x, 2) + pow(one.y - two.y, 2)));
}

float manhattan(struct point_t one, struct point_t two)
{
        float dist =  fabs(one.x - two.x) + fabs(one.y - two.y);
        return dist;
}