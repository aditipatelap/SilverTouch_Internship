#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main(){
    // define the variable
    int num;
    bool check = true;
    
    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &num);
    
    // check number is prime or not
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            printf("%d is not prime number.", num);
            check = false;
            break;
        }
    }
    if (check) {
        printf("%d is prime number.", num);
    }

    return 0;
}