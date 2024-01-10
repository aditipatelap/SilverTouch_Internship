#include <stdio.h>

void calculateDiagonalSum(int matrix[100][100], int rows, int cols) {
    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;

    // Calculate the sum of the primary diagonal
    for (int i = 0; i < rows; i++) {
        primaryDiagonalSum += matrix[i][i];
    }

    // Calculate the sum of the secondary diagonal
    for (int i = 0; i < rows; i++) {
        secondaryDiagonalSum += matrix[i][cols - i - 1];
    }

    // Print the results
    printf("Sum of the primary diagonal: %d\n", primaryDiagonalSum);
    printf("Sum of the secondary diagonal: %d\n", secondaryDiagonalSum);
}

int main() {
    int rows, cols;

    // Get the size of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Get the matrix elements from the user
    int matrix[100][100];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the diagonal sums
    calculateDiagonalSum(matrix, rows, cols);

    return 0;
}