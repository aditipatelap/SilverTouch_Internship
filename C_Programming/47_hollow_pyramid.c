#include <stdio.h>

void printHollowPyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (k == 1 || k == (2 * i - 1) || i == rows) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Get the number of rows for the hollow pyramid
    int rows;
    printf("Enter the number of rows for the hollow pyramid: ");
    scanf("%d", &rows);

    // Print the hollow pyramid
    printHollowPyramid(rows);

    return 0;
}