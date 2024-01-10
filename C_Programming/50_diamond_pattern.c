#include <stdio.h>

void printDiamond(int rows) {
    int i, j;

    // Print the top half of the diamond
    for (i = 1; i <= rows; i++) {
        for (j = i; j < rows; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the bottom half of the diamond
    for (i = rows - 1; i >= 1; i--) {
        for (j = rows; j > i; j--) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    // Get the number of rows for the diamond pattern
    int rows;
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &rows);

    // Print the diamond pattern
    printDiamond(rows);

    return 0;
}