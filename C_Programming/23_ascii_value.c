#include<stdio.h>

int main(){
    // define variables
    char ch;

    // get the character
    printf("Enter a character:");
    scanf("%c", &ch);

    // output
    printf("ASCII value of %c is %d.", ch, ch);

    return 0;
}