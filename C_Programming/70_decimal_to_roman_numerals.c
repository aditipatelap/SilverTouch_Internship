#include <stdio.h>

// Function to convert decimal to Roman numerals
void decimalToRoman(int num) {
    // Arrays to store Roman numeral symbols and their corresponding values
    char romanSymbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};

    // Initialize variables
    int i = 6;  // Index for the arrays (start from the largest Roman numeral)
    int digit;

    // Iterate through each digit place and convert to Roman numeral
    while (num > 0) {
        // Get the current digit
        digit = num / values[i];
        num %= values[i];

        // Process the current digit place
        if (digit > 0) {
            if (digit == 9) {
                printf("%c%c", romanSymbols[i], romanSymbols[i + 2]);
            } else if (digit >= 5) {
                printf("%c", romanSymbols[i + 1]);
                for (int j = 0; j < digit - 5; j++) {
                    printf("%c", romanSymbols[i]);
                }
            } else if (digit == 4) {
                printf("%c%c", romanSymbols[i], romanSymbols[i + 1]);
            } else {
                for (int j = 0; j < digit; j++) {
                    printf("%c", romanSymbols[i]);
                }
            }
        }

        // Move to the next smaller Roman numeral
        i -= 2;
    }

    printf("\n");
}

int main() {
    int num;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Check if the number is within the valid range (1 to 3999)
    if (num >= 1 && num <= 3999) {
        // Convert and print the Roman numeral representation
        printf("Roman numeral: ");
        decimalToRoman(num);
    } else {
        printf("Error: Please enter a valid number between 1 and 3999.\n");
    }

    return 0;
}