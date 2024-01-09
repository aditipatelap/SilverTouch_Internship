#include <stdio.h>

int reverse_num(int num){
    int reverse = 0;
    while (num != 0){
        reverse = reverse * 10 + num % 10;
        num = num / 10;
    }
    return reverse;
}

int main() {
    // define the variable
    int num;

    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &num);

    // reverse the numbers
    int reverse = reverse_num(num);

    // print the reversed number
    printf("Reverse of number is %d", reverse);
    return 0;
}