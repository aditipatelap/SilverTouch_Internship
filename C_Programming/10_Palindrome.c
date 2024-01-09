#include<stdio.h>
#include<math.h>

/* Palindrome means sequence that reads the same backwards as forwards. */

int reverse_num(int num){
    int reverse = 0;
    while (num != 0){
        reverse = reverse * 10 + num % 10;
        num = num / 10;
    }
    return reverse;
}

int main(){
    // define the variable
    int original;

    // get the number
    printf("Enter Integer Number:");
    scanf("%d", &original);

    // Algorithm: check the reverse and original number if same then they are palindrome. 
    int reverse = reverse_num(original);

    if (reverse == original){
        printf("%d is Palindrome.", original);
    }
    else{
        printf("%d is not palindrome.", original);
    }
    return 0;
}