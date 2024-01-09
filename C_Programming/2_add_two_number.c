#include<stdio.h>

int main(){
    // define the variables
    float num1, num2, sum;

    // get the first number
    printf("Enter Number 1:");
    scanf("%f", &num1);

    // get the second number
    printf("Enter Number 2:");
    scanf("%f", &num2);

    // add two numbers
    sum = num1 + num2;

    // print the output
    printf("Result: %.2f + %.2f = %.2f", num1, num2, sum);
    
    return 0;
}