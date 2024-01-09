#include<stdio.h>

int factorial(int num){
    if(num == 0){
        return 1;
    }
    return num * factorial(num-1);
}

int main(){
    // define the variables
    int num;

    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &num);

    // calculate the factorial
    int res = factorial(num);
    
    // print the result
    printf("%d! = %d", num, res);

    return 0;
}