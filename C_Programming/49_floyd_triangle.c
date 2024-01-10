#include <stdio.h>

void printFloydsTriangle(int rows) {
    int number = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", number);
            number++;
        }
        printf("\n");
    }
}

int main() {
    // Get the number of rows for Floyd's Triangle
    int rows;
    printf("Enter the number of rows for Floyd's Triangle: ");
    scanf("%d", &rows);

    // Print Floyd's Triangle
    printFloydsTriangle(rows);

    return 0;
}