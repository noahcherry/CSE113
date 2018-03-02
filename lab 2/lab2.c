/**
 * @file lab1.c
 * @brief Basic geometry calculator
 * 
 * @author Noah Cherry
 * @date Spring 2015
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* function prototypes*/
int area_rectangle( int h, int w);
int perimeter_rectangle( int h, int w);
float diagonal_rectangle( float h, float w);
float area_circle( float r );
float circumference( float r );
float area_triangle( float b, float h );
float hypotenuse(float b, float h);
float perimeter_triangle( float b, float h);
float exterior_angle( float s );
float interior_angle( float s );
float area_regular_polygon( float l, int s);

int main(void)
{

    /*declared variables*/
    int sides = 0;
    int rh = 0;
    int rw = 0;  
    float drh = 0;
    float drw = 0;
    float radius = 0;
    float tb = 0;
    float th = 0;
    float lengths = 0;
    
    int in;
    int tmp;
    int tmp2;
    char s[1024];

    printf("Welcome to math hell!\n Pick a level of torment:\n");
    printf("C. Circles\n");
    printf("P. regular Polygons\n");
    printf("R. Rectangles\n");
    printf("T. Triangles\n");
    printf("Please enter your choice (C, P, R, T): ");
    while ((tmp = getchar()) != '\n')
        in = tmp;

    switch (in) {
    case 'C':
    case 'c':
        printf("A. Area of a circle\n");
        printf("C. Circumference of a circle\n");
        printf("Please enter your choice (A, C): ");
        while ((tmp2 = getchar()) != '\n')
            in = tmp2;
        switch (in) {
        case 'A':
        case 'a':
             /* prompts for values to solve area of a circle with*/
            printf("The radius of your circle is...");
            fgets(s, 1024, stdin);
            radius = atof(s);
            if (radius == 0) {
                printf("Your circle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(radius < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The area is %f\n", area_circle( radius ));   
            break;
        case 'C':
        case 'c':
            /* prompts for values to solve circumference with*/
            printf("The radius of your circle is...");
            fgets(s, 1024, stdin);
            radius = atof(s);
            if (radius == 0) {
                printf("Your circle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }     
            if(radius < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The circumference is %f\n",circumference( radius ));
            break;
        default:
            printf("Ya goofed it up, ya dingus!\n");
            }
        break;
    case 'P':
    case 'p':
        printf("A. Area of a regular polygon\n");
        printf("E. Exterior angle of a regular polygon\n");
        printf("I. Interior angle of a regular polygon\n");
        printf("Please enter your choice(A, E, I): ");
        while ((tmp2 = getchar()) != '\n')
            in = tmp2;
        switch (in) {
        case 'A':
        case 'a':
            /* prompts for values to solve area of a regular polygon with*/
            printf("The number of sides your shape has...");
            fgets(s, 1024, stdin);
            sides = atoi(s);
            if (sides == 0) {
                printf("division by zero.\n");
                return 1;
            }     
            if(sides < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The length of your shapes sides...");
            fgets(s, 1024, stdin);
            lengths = atof(s);
            if (lengths == 0) {
                printf("Your polygon doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(lengths < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The area is %f\n", area_regular_polygon( lengths , sides));
            break;
        case 'E':
        case 'e':
            /* prompts for values to solve exterior angle with*/
            printf("The number of sides your shape has...");
            fgets(s, 1024, stdin);
            sides = atoi(s);
            if (sides == 0) {
                printf("division by zero.\n");
                return 1;
            }
            if(sides < 0) {
                printf("Negative numbers are sinful\n");
                return 1;
            }
            printf("The exterior angle is %f\n", exterior_angle( sides));
            break;
        case 'I':
        case 'i':
            /* prompts for values to solve interior angle with*/
            printf("The number of sides your shape has...");
            fgets(s, 1024, stdin);
            sides = atoi(s);
            if (sides == 0) {
                printf("division by zero.\n");
                return 1;
            }            
            if(sides < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The interior angle is %f\n", interior_angle( sides));
            break;
        default:
            printf("Ya goofed it up, ya dingus!\n");
            }
        break;
    case 'R':
    case 'r':
        printf("A. Area of a rectangle\n");
        printf("D. Diagonal of a regtangle\n");
        printf("P. Perimeter of a rectangle\n");
        printf("Please enter your choice (A, D, P): ");
        while ((tmp2 = getchar()) != '\n')
            in = tmp2;
        switch (in) {
        case 'A':
        case 'a':
            /* prompts for values to solve area of a rectangle with*/
            printf("The height of your rectangle is...");
            fgets(s, 1024, stdin);
            rh = atoi(s);
            if (rh == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(rh < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("and width...");
            fgets(s, 1024, stdin);
            rw = atoi(s);
            if (rw == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(rw < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The area is %d\n", area_rectangle( rh, rw ));
            break;
        case 'D':
        case 'd':
            /* prompts for values to solve diagonal of a rectangle with*/
            printf("The height of your rectangle is...");
            fgets(s, 1024, stdin);
            drh = atof(s);
            if (drh == 0) {
                printf("Your rectangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(drh < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("and width...");
            fgets(s, 1024, stdin);
            drw = atof(s);
            if (drw == 0) {
                printf("Your rectangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(drw < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The diagonal of this is %f\n", diagonal_rectangle( drh, drw ));
            break;
        case 'P':
        case 'p':
            /* prompts for values to solve perimeter of a rectangle with*/
            printf("The height of your rectangle is...");
            fgets(s, 1024, stdin);
            rh = atoi(s);
            if (rh == 0) {
                printf("Your rectangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(rh < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("and width...");
            fgets(s, 1024, stdin);
            rw = atoi(s);
            if (rw == 0) {
                printf("Your rectangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(rw <= 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The perimeter is %d\n", perimeter_rectangle( rh, rw ));
            break;
        default:
            printf("Ya goofed it up, ya dingus!\n");
            }
        break;
    case 'T':
    case 't':
        printf("A. Area of a triangle\n");
        printf("P. Perimeter of a triangle\n");
        printf("Please enter your choice (A, P): ");
        while ((tmp2 = getchar()) != '\n')
            in = tmp2;
        switch (in) {
        case 'A':
        case 'a':
            /* prompts for values to solve area of a triangle with*/
            printf("The height of your triangle is...");
            fgets(s, 1024, stdin);
            th = atof(s);
            if (th == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(th < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("and base...");
            fgets(s, 1024, stdin);
            tb = atof(s);
            if (tb == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(tb <= 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The area isis %f\n", area_triangle( th, tb ));
            break;
        case 'P':
        case 'p':
            /* prompts for values to solve perimeter of a triangle with*/
            printf("The height of your triangle is...");
            fgets(s, 1024, stdin);
            th = atof(s);
            if (th == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(th < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("and base...");
            fgets(s, 1024, stdin);
            tb = atof(s);
            if (tb == 0) {
                printf("Your triangle doesn't exist. Directed by M. Night Shyamalan.\n");
                return 1;
            }  
            if(tb < 0) {
                printf("input < 0. Negative numbers are sinful\n");
                return 1;
            }
            printf("The perimeter is %f\n", perimeter_triangle( th, tb));
            break;
        default:
            printf("Ya goofed it up, ya dingus!\n");
            }
        break;
    default:
        printf("Ya goofed it up, ya dingus!\n");
    }
   
    return 0;
}

/** Calculates the area of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the area of the rectangle
 */
int area_rectangle( int h, int w)
{
    return w * h;
}

/** Calculates the perimeter of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the perimeter of the rectangle
 */
int perimeter_rectangle( int h, int w)
{
    return 2 * (w + h);
}

/** Calculates the distance between opposite corners of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the distance between two opposite corners of the rectangle
 */
float diagonal_rectangle( float h, float w)
{
    return sqrt(h*h+w*w);
}

/** Calculates the area of a circle
 * @param r, the radius of the circle
 * @return the area of the circle
 */
float area_circle(float r)
{
    return 3.141593 * pow(r,2);
}

/** Calculates the circumference of a circle
 * @param r, the radius of the circle
 * @return the circumference of the circle
 */
float circumference(float r)
{
    return 3.141593 * 2 * r;
}

/** Calculates the area of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the area of the triangle
 */
float area_triangle( float b, float h )
{
    return .5 * b * h;
}

/** Calculates the hypotenuse of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the hypotenuse of the triangle
 */
float hypotenuse( float b, float h)
{
    return diagonal_rectangle( b, h );
}

/** Calculates the perimeter of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the perimeter of the triangle
 */
float perimeter_triangle(float b, float h)
{
    return b + h + diagonal_rectangle( b, h );
}

/** Calculates the exterior angle of a shape
 * @param s, the number of sides the shape has
 * @return the exterior angle of the shape
 */
float exterior_angle( float s )
{
    return 360 / s;
}

/** Calculates the interior angle of a shape
 * @param s, the number of sides the shape has
 * @return the interior angle of the shape
 */
float interior_angle( float s )
{
    return ( 180 * ( s - 2 )) / s;
}

/** Calculates the area of a regular polygon
 * @param s, the number of sides the shape has
 * @param l, the length of the sides of the shape
 * @return the area of the regular polygon
 */
float area_regular_polygon( float l , int s ) 
{
    return (pow(l,2) * s)/(4 * tan(3.141593/s));
}