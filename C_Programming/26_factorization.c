#include<stdio.h>

void factorize(int num){
    printf("Prime factors of %d are:", num);

    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            printf(" %d", i);
        }
    }
}

int main(){
    // define variables
    int number;
    
    // get the number
    printf("Enter Number:");
    scanf("%d", &number);

    // Check if the entered number is positive
    if (number <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1; // Exit with an error code
    }

    // print factors
    factorize(number);
    
    return 0;
}