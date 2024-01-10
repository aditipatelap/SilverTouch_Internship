#include<stdio.h>

void countVowelsConsonants(char *str, int *vowels, int *consonants){
    while(*str){
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
            (*vowels)++;
        else{
            (*consonants)++;
        }
        str++;
    }
}

int main(){
    // define variables
    char inputString[100];
    int vowels = 0, consonants = 0;

    // get input string
    printf("Enter String: ");
    scanf("%s", inputString);

    // count vowels and consonants
    countVowelsConsonants(inputString, &vowels, &consonants);

    // Print the result
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}