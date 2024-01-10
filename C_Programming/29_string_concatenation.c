#include<stdio.h>

int main(){
    // define the variables
    char str1[100], str2[100];

    // get the input strings
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // concat the strings
    strcat(str1, str2);

    // print output
    printf("The concatenated string is: %s\n", str1);

    return 0;
}
