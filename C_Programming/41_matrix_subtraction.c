#include <stdio.h>

// Function to subtract two matrices
void subtractMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define matrices
    int mat1[100][100], mat2[100][100], result[100][100];
    int rows, cols;

    // Get the input for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Get the input for the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Get the input for the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Perform matrix subtraction
    subtractMatrices(mat1, mat2, result, rows, cols);

    // Display the matrices and their difference
    printf("Matrix 1:\n");
    printMatrix(mat1, rows, cols);

    printf("Matrix 2:\n");
    printMatrix(mat2, rows, cols);

    printf("Difference of matrices:\n");
    printMatrix(result, rows, cols);

    return 0;
}