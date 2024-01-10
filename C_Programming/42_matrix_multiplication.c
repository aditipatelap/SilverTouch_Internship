#include <stdio.h>

// Function to multiply two matrices
void multiplyMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
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
    int rows1, cols1, rows2, cols2;

    // Get the input for matrix dimensions
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with the given dimensions.\n");
        return 1; // Exit with an error code
    }

    // Get the input for the first matrix
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Get the input for the second matrix
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Perform matrix multiplication
    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);

    // Display the matrices and their product
    printf("Matrix 1:\n");
    printMatrix(mat1, rows1, cols1);

    printf("Matrix 2:\n");
    printMatrix(mat2, rows2, cols2);

    printf("Product of matrices:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}