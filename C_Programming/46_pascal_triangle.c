#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate binomial coefficient C(n, k)
long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lld ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    // Get the number of rows for Pascal's Triangle
    int rows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    // Print Pascal's Triangle
    printPascalsTriangle(rows);

    return 0;
}