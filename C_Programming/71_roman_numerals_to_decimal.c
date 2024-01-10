#include <stdio.h>
#include <string.h>

// Function to convert Roman numerals to decimal
int romanToDecimal(char *roman) {
    // Define the values for each Roman numeral symbol
    int values[7] = {1, 5, 10, 50, 100, 500, 1000};
    
    // Function to get the decimal value of a Roman numeral character
    int getDecimalValue(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1; // Invalid Roman numeral character
        }
    }

    int result = 0;
    int prevValue = 0;

    // Iterate through the Roman numeral characters from right to left
    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int currentValue = getDecimalValue(roman[i]);

        // Check if the current numeral is smaller than the previous numeral
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

int main() {
    char roman[20];

    // Get the Roman numeral from the user
    printf("Enter a Roman numeral: ");
    fgets(roman, sizeof(roman), stdin);

    // Remove newline character from the input
    size_t len = strlen(roman);
    if (len > 0 && roman[len - 1] == '\n') {
        roman[len - 1] = '\0';
    }

    // Convert and print the decimal representation
    int decimal = romanToDecimal(roman);

    if (decimal != -1) {
        printf("Decimal representation: %d\n", decimal);
    } else {
        printf("Error: Invalid Roman numeral.\n");
    }

    return 0;
}