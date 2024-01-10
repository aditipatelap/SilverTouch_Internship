#include <stdio.h>

void printNumberPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    // Get the number of rows for the number pattern
    int rows;
    printf("Enter the number of rows for the number pattern: ");
    scanf("%d", &rows);

    // Print the number pattern
    printNumberPattern(rows);

    return 0;
}