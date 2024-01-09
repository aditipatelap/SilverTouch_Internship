#include<stdio.h>

int gcd(int num1, int num2){
    /* algorithm:
    smaller integer is subtracted from the larger integer, 
    and the result is assigned to the variable holding larger integer. 
    This process is continued until num1 and num2 are equal.
    */
    while(num1 != num2){
        if(num1 > num2){
            num1 = num1 - num2;
        }
        else{
            num2 = num2 - num1;
        }
    }
    return num1;
}
int main(){
    // define the variables
    int num1, num2, res;

    // get the first number
    printf("Enter Number 1:");
    scanf("%d", &num1);

    // get the second number
    printf("Enter Number 2:");
    scanf("%d", &num2); 

    // if user enters negative number, sign of the number is changed to positive
    num1 = (num1 > 0) ? num1 : -num1;
    num2 = (num2 > 0) ? num2 : -num2;

    // calculate the gcd
    res = gcd(num1, num2);
    
    // print the result
    printf("The GCD of %d and %d is %d", num1, num2, res);

    return 0;
}