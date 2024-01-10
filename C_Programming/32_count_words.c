#include<stdio.h>
#include<stdbool.h>

// Function to count words in a sentence
int countWords(char *sentence) {
    int count = 0;
    bool inWord = false;

    // Iterate through each character in the sentence
    while (*sentence) {
        // Check if the current character is a space or a punctuation mark
        if (*sentence == ' ' || *sentence == '\t' || *sentence == '\n' || *sentence == '\r' || *sentence == '\v' || *sentence == '\f') {
            inWord = false;
        } else {
            // If the current character is not a space or punctuation mark
            // and we were not in a word previously, increment the word count
            if (!inWord) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
        sentence++;
    }

    return count;
}

int main(){
    // define variables
    char sentence[50000];

    // Get input sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from the input
    sentence[strcspn(sentence, "\n")] = '\0';

    // Count the words and print the result
    int wordCount = countWords(sentence);
    printf("Number of words: %d\n", wordCount);

    return 0;
}