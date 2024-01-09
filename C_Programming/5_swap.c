#include<stdio.h>

int main(){
    // define the variables
    float num1, num2;

    // get the first number
    printf("Enter Number 1:");
    scanf("%f", &num1);

    // get the second number
    printf("Enter Number 2:");
    scanf("%f", &num2);

    // swap the numbers
    float temp = num1;
    num1 = num2;
    num2 = temp;
    
    // print the numbers
    printf("Number 1: %.3f\n", num1);
    printf("Number 2: %.3f\n", num2);

    return 0;
}