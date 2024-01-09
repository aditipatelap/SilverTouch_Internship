#include<stdio.h>
#include<math.h>
/*
Triangle Area --> Heron's formula
area = sqrt(s * (s - a) * (s - b) * (s - c))
where; s = (a+b+c)/2
*/ 

int main(){
    //define the variables
    double a, b, c, s, area;

    // Get the lengths of the three sides of triangle
    printf("Enter the length of side a: ");
    scanf("%lf", &a);

    printf("Enter the length of side b: ");
    scanf("%lf", &b);

    printf("Enter the length of side c: ");
    scanf("%lf", &c);

    // Check if the sides form a valid triangle (triangle inequality theorem)
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (b + c <= a) || (c + a <= b)) {
        printf("Error: Invalid triangle sides. Please make sure they form a valid triangle.\n");
        return 1; // Exit with an error code
    }

    // Calculate the semi-perimeter
    s = (a + b + c) / 2;

    // Calculate the area using Heron's formula
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Print the result
    printf("Area of the triangle is %.4f\n", area);

    return 0;
}