#include<stdio.h>

void deciToBinary(int num){
    int binaryNum[40];
    int i = 0;
    while(num > 0){
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    // binary values store in arrayb in reverse order.
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
    
}

int main(){
    // define the variable
    int num;

    // get the number
    printf("Enter decimal number:");
    scanf("%d", &num);

    // convert decimal to binary number
    printf("Binary representation of %d is: ", num);
    deciToBinary(num);

    return 0;
}