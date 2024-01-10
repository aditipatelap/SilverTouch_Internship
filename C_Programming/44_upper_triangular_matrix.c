#include <stdio.h>

// Function to check if a matrix is upper triangular
int isUpperTriangular(int mat[][100], int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != 0) {
                return 0; // Not an upper triangular matrix
            }
        }
    }
    return 1; // It is an upper triangular matrix
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
    // Define matrix
    int mat[100][100];
    int rows, cols;

    // Get the input for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Get the input for the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Check if the matrix is upper triangular
    if (isUpperTriangular(mat, rows, cols)) {
        printf("The matrix is an upper triangular matrix.\n");
    } else {
        printf("The matrix is not an upper triangular matrix.\n");
    }

    // Display the matrix
    printf("Matrix:\n");
    printMatrix(mat, rows, cols);

    return 0;
}