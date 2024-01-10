#include <stdio.h>

// Function to transpose a matrix
void transposeMatrix(int mat[][100], int transposed[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
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
    int mat[100][100], transposed[100][100];
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

    // Perform matrix transposition
    transposeMatrix(mat, transposed, rows, cols);

    // Display the original and transposed matrices
    printf("Original Matrix:\n");
    printMatrix(mat, rows, cols);

    printf("Transposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    return 0;
}