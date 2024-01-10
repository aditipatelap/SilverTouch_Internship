#include <stdio.h>

int isMagicSquare(int matrix[100][100], int n) {
    // Calculate the sum of the first row
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += matrix[0][j];
    }

    // Check the sum of each row
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }

        if (rowSum != sum) {
            return 0; // Not a magic square
        }
    }

    // Check the sum of each column
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }

        if (colSum != sum) {
            return 0; // Not a magic square
        }
    }

    // Check the sum of the main diagonal
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += matrix[i][i];
    }

    if (mainDiagonalSum != sum) {
        return 0; // Not a magic square
    }

    // Check the sum of the secondary diagonal
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }

    if (secondaryDiagonalSum != sum) {
        return 0; // Not a magic square
    }

    // If all checks passed, it is a magic square
    return 1;
}

int main() {
    int n;

    // Get the size of the square matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Get the matrix elements from the user
    int matrix[100][100];
    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if it is a magic square and print the result
    if (isMagicSquare(matrix, n)) {
        printf("It is a magic square.\n");
    } else {
        printf("It is not a magic square.\n");
    }

    return 0;
}