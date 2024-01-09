#include<stdio.h>
#include<math.h>

// M_PI is a constant in the math.h library representing the value of π (pi).
// Circle Area = π × radius*2
int main(){
    // define the variables
    double radius, area;

    // Get the radius
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Check if the radius is non-negative
    if (radius < 0) {
        printf("Error: Radius cannot be negative.\n");
        return 1; // Exit with an error code
    }

    // Calculate the area
    area = M_PI * pow(radius, 2);

    // Print the result
    printf("Area of the circle with radius %.2f is %.2f\n", radius, area);

    return 0;
}