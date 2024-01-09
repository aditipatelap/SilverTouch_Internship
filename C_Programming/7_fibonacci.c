#include<stdio.h>

void fibonacci(int terms){
    // In fibonacci third = second + first
    // define and print first & second terms
    int t1 = 0, t2 = 1;

    printf("----------- fibonacci series -----------\n");
    printf("%d  %d  ", t1, t2);
    
    for (int i = 3; i <= terms; i++)
    {
        int t3 = t1 + t2;
        printf("%d  ", t3);
        t1 = t2;
        t2 = t3;
    }
}

int main(){
    // define the variables
    int terms;

    // get the number
    printf("Enter the number of terms for fibonacci series:");
    scanf("%d", &terms);

    if (terms <= 2)
    {
        printf("Number of terms for fibonacci series should be greater than 2.");
    }
    else{
        // print the series
        fibonacci(terms);
    }
    
    return 0;
}