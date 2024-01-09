#include<stdio.h>

/*
Perfect number: positive integer that is equal to the sum of its proper divisors, excluding itself.
*/

int main(){
    // define variables
    int number, sum = 0;
    
    // get the number
    printf("Enter Number:");
    scanf("%d", &number);

    // Check if the entered number is positive
    if (number <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1; // Exit with an error code
    }

    // check is number is perfect or not
    // find divisor and add up them
    for(int i = 1; i <= number / 2; i++){
        if(number % i == 0){
            sum += i;
        }
    }
    
    // print the output
    if(sum == number){
        printf("This is Perfect Number.");
    }
    else{
        printf("This is not Perfect Number.");
    }
    
    return 0;
}