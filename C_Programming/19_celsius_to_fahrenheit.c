#include<stdio.h>

// F = (C * 9 / 5) + 32
int main(){
    // define variables
    double celsius, fahrenheit;

    // input
    printf("Enter temperature in celsius: ");
    scanf("%lf", &celsius);

    // conversion
    fahrenheit = (celsius * 9 / 5) + 32;

    // output
    printf("Temperature in Fahrenheit: %lf", fahrenheit);

    return 0;
}