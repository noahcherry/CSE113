/**
 * @file lab1.c
 * @brief Basic geometry calculator
 * 
 * @author Noah Cherry
 * @date Spring 2015
 * @todo make main an infinite loop with an exit case
 */
#include <stdio.h>
#include <math.h>

/* function prototypes*/
int area_rectangle(int height, int width);
int perimeter_rectangle(int height, int width);
double diagonal_rectangle(float height, float width);
float area_circle(double radius);
float circumference(double radius);
float area_triangle(double base, double height);
float hypotenuse(double base, double height);
float perimeter_triangle(double base, double height);
float exterior_angle(int sides);
float interior_angle(int sides);
float sum_interior_angle(int sides);
float area_regular_polygon(float length, int sides);

int main(void)
{
        int sides = 0;
        int calc = 0;
        float rh = 0;
        float rw = 0;  
        float radius = 0;
        float tb = 0;
        float th = 0;
        float lengths = 0;


        printf("1. Rectangle Calculations\n2. Circle Calculations\n3. Triangle Calculations\n4. Regular Polygon Calculations\n");
        scanf("%d", &calc);

        switch (calc) {
        case 1:
                /* prompts for values to solve area of a rectangle with*/
                printf("The height of your rectangle is...");
                scanf("%f", &rh);
                printf("and width...");
                scanf("%f", &rw);
                printf("The area is %d\n", area_rectangle(rh, rw));
                printf("The perimeter is %d\n", perimeter_rectangle(rh, rw));
                printf("The diagonal of this is %f\n", diagonal_rectangle(rh, rw));
                break;
        case 2:
                /* prompts for values to solve area of a circle with*/
                printf("The radius of your circle is...");
                scanf("%f", &radius);
                printf("The area is %f\n", area_circle(radius));
                printf("The circumference is %f\n",circumference(radius));
                break;
        case 3:
                /* prompts for values to solve area of a triangle with*/
                printf("The height of your triangle is...");
                scanf("%f", &th);
                printf("and base...");
                scanf("%f", &tb);
                printf("The area is %f\n", area_triangle(th, tb));
                printf("The perimeter is %f\n", perimeter_triangle(th, tb));
                break;
        case 4:
                /* prompts for values to solve exterior angle with*/
                printf("The number of sides your shape has...");
                scanf("%d", &sides);
                printf("The length of your shapes sides...");
                scanf("%f", &lengths);
                printf("The exterior angle is %f\n", exterior_angle(sides));
                printf("The interior angle is %f\n", interior_angle(sides));
                printf("The sume of the interior angles is %f\n", sum_interior_angle(sides));
                printf("The area is %f\n", area_regular_polygon(lengths , sides));
                break;
        default:
                printf("Try a number that does something next time");
        }


        return 0;
}

/** Calculates the area of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the area of the rectangle
 */
int area_rectangle(int height, int width)
{
    return width * height;
}

/** Calculates the perimeter of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the perimeter of the rectangle
 */
int perimeter_rectangle(int height, int width)
{
    return 2 * (width + height);
}

/** Calculates the distance between opposite corners of a rectangle
 * @param h, the height of the rectangle
 * @param w, the width of the rectangle
 * @return the distance between two opposite corners of the rectangle
 */
double diagonal_rectangle(float height, float width)
{
    return sqrt((height * height) + (width * width));
}

/** Calculates the area of a circle
 * @param r, the radius of the circle
 * @return the area of the circle
 */
float area_circle(double radius)
{
    return 3.141593 * pow(radius, 2);
}

/** Calculates the circumference of a circle
 * @param r, the radius of the circle
 * @return the circumference of the circle
 */
float circumference(double radius)
{
    return 3.141593 * 2 * radius;
}

/** Calculates the area of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the area of the triangle
 */
float area_triangle(double base, double height)
{
    return .5 * base * height;
}

/** Calculates the hypotenuse of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the hypotenuse of the triangle
 */
float hypotenuse(double base, double height)
{
    return hypot(base, height);
}

/** Calculates the perimeter of a triangle
 * @param h, the height of the triangle
 * @param b, the base of the triangle
 * @return the perimeter of the triangle
 */
float perimeter_triangle(double base, double height)
{
    return base + height + hypotenuse(base, height);
}

/** Calculates the exterior angle of a regular polygon
 * @param s, the number of sides the shape has
 * @return the exterior angle of the shape
 */
float exterior_angle(int sides)
{
    return 360 / sides;
}

/** Calculates the interior angle of a regular polygon
 * @param s, the number of sides the shape has
 * @return the interior angle of the shape
 */
float interior_angle(int sides)
{
    return (180 *(sides - 2)) / sides;
}

/** Calculates the sum of the interior angles of a regular polygon
 * @param s, the number of sides the shape has
 * @return the interior angle of the shape
 */
float sum_interior_angle(int sides)
{
    return (180 *(sides - 2));
}

/** Calculates the area of a regular polygon
 * @param s, the number of sides the shape has
 * @param l, the length of the sides of the shape
 * @return the area of the regular polygon
 */
float area_regular_polygon(float length, int sides) 
{
    return (pow(length, 2) * sides)/(4 * tan(3.141593 / sides));
}