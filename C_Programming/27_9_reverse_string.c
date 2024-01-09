#include<stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    
    // Swap characters from the beginning and end of the string
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(){
    
    return 0;
}