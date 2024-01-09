#include<stdio.h>

int main() {
    // define the variable
    int num;
    
    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &num);
    
    // check number is odd or even
    if(num%2 == 0){
        printf("%d is even.", num);
    }
    else{
        printf("%d is odd.", num);
    }

    return 0;
}