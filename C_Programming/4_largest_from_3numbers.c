#include<stdio.h>

int main() {
    // define the variables
    float num1, num2, num3;

    // get the first number
    printf("Enter Number 1:");
    scanf("%f", &num1);

    // get the second number
    printf("Enter Number 2:");
    scanf("%f", &num2);
    
    // get the third number
    printf("Enter Number 3:");
    scanf("%f", &num3);
    
    // find the largest one
    if(num1 >= num2){
        if(num1 >= num3){
            printf("%f is largest number.", num1);
        }
        else{
            printf("%f is largest number.", num3);
        }
    }
    else{
        if(num2 >= num3){
            printf("%f is largest number.", num2);
        }
        else{
            printf("%f is largest number.", num3);
        }
    }

    return 0;
}