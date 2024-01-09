#include<stdio.h>

int main(){
    // define the variable
    int num, sum = 0;

    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &num);

    // calculate the sum
    while(num!= 0){
        sum += num % 10;
        num /= 10;
    }

    // print the sum
    printf("Sum of the digits of is %d", sum);
    
    return 0;
}