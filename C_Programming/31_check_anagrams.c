#include<stdio.h>

// Anagram of a string: another string that is formed by the rearrangement of the same set of characters.
int areAnagrams(char *str1, char *str2){
     // total ascii characters are 256
    int freq[256];

    // check the length of the string
    if(strlen(str1) != strlen(str2)){
        return 0;
    }

    // increment the freq of character by one string
    for(int i = 0; i < strlen(str1); i++){
        // increment frequency of character
        freq[(int)str1[i]]++;
    }

    // decrement the freq of character by one string
    for(int i = 0; i < strlen(str2); i++){
        // decrement frequency of character
        freq[(int)str2[i]]--;
    }

    // check all frequencies of characters. it should be zero.
    for (int i = 0; i < strlen(freq); i++)
    {
        if(freq[i] != 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    // define the variables
    char str1[100], str2[100];

    // get the input strings
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);
    
    // // Check if the strings are anagrams
    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}