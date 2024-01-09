#include<stdio.h>
#include<math.h>

int main(){
    // define the variables
    char operator;
    float num1, num2, result;

    // get the operator
    printf("Enter Operator:");
    scanf("%c", &operator);

    // get the first number
    printf("Enter Number 1:");
    scanf("%f", &num1);

    // get the second number
    printf("Enter Number 2:");
    scanf("%f", &num2);

    // perform the operation
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
            
        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if(num2!= 0){
                result = num1 / num2;
            }
            else{
                printf("Cannot divide by 0\n");
            }
            break;
        default:
            printf("Invalid operator\n");
            break;
    }

    // print the result
    printf("Result: %.4f\n", result);

    return 0;
}