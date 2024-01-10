#include<stdio.h>

int main(){
    // define the variables
    char str[100];
    int len = 0;

    // get the input strings
    printf("Enter the string: ");
    scanf("%s", str);

    // length of the string
    len = strlen(str);

    // print output
    printf("The length of string is: %d\n", len);

    return 0;
}