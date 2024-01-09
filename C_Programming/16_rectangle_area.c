#include<stdio.h>

// Rectangle Area = length * width;
int main(){
    // define variables
    double length, width, area;

    // get input
    printf("Enter length: ");
    scanf("%lf", &length);
    printf("Enter width: ");
    scanf("%lf", &width);

    // Check if length and width are non-negative
    if (length < 0 || width < 0) {
        printf("Error: Length/Width cannot be negative.\n");
        return 1; // Exit with an error code
    }

    // calculate area
    area = length * width;

    // print output
    printf("Area = %lf\n", area);

    return 0;
}