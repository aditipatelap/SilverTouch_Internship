#include<stdio.h>

/*
Armstrong number (narcissistic number, pluperfect digital invariant, or pluperfect number):
sum of its own digits each raised to the power of the number of digits
*/
int countDigits(int num){
    int count = 0;
    while(num != 0){
        count++;
        num /= 10;
    }
    return count;
}
int main(){
    // define variables
    int number, originalNum, digits, sum;
    
    // get the number
    printf("Enter Number:");
    scanf("%d", &number);

    // Check if the entered number is positive
    if (number <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1; // Exit with an error code
    }

    // check is number is armstrong or not
    digits = countDigits(number);
    printf("%d\n", digits);
    originalNum = number;
    while(number != 0){
        sum += pow(number%10, digits);
        number /= 10;
    }

    // print the output
    if(sum == originalNum){
        printf("This is an Armstrong Number.");
    }
    else{
        printf("This is not an Armstrong Number.");
    }

    return 0;
}