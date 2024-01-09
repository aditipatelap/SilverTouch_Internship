#include<stdio.h>

// C = 5 / 9 * (F - 32)
int main(){
    // define variables
    double celsius, fahrenheit;

    // input
    printf("Enter temperature in fahrenheit: ");
    scanf("%lf", &fahrenheit);

    // conversion
    celsius =(fahrenheit - 32) *  5 / 9 ;

    // output
    printf("Temperature in Celsius: %lf", celsius);

    return 0;
}