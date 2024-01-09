#include<stdio.h>

void binaryToDeci(long long binary){
    int decimal = 0;
    for (int i = 0; binary != 0; i++)
    {
        decimal += (binary % 10) * pow(2, i);
        binary /= 10;
    }
    
    printf("%d", decimal);
}

int main(){
    // define the variable
    long long binary;

    // get the number
    printf("Enter binary number:");
    scanf("%d", &binary);

    // convert decimal to binary number
    printf("Decimal representation of %d is: ", binary);
    binaryToDeci(binary);

    return 0;
}