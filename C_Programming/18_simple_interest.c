#include<stdio.h>

int main(){
    // define the variables
    double principal, rate, interest;
    int time;

    // get input data from user
    printf("Principal amount(in INR): ");
    scanf("%lf", &principal);

    printf("Rate of interest per year(in %): ");
    scanf("%lf", &rate);

    printf("Duration(in year): ");
    scanf("%d", &time);
    
    // calculate the interest
    interest = (principal * rate * time) / 100;

    // print the result
    printf("You will get %.2lf INR simple interest after %d years.\n", interest, time);

    return 0;
}