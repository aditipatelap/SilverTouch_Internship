#include <stdio.h>

// Function to calculate GCD of two numbers
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM of two numbers
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

// Function to find GCD of an array of numbers
int findArrayGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = findGCD(result, arr[i]);
    }
    return result;
}

// Function to find LCM of an array of numbers
int findArrayLCM(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = findLCM(result, arr[i]);
    }
    return result;
}

int main() {
    int n;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the array elements from the user
    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and print the GCD and LCM
    int arrayGCD = findArrayGCD(arr, n);
    int arrayLCM = findArrayLCM(arr, n);

    printf("GCD of the array elements: %d\n", arrayGCD);
    printf("LCM of the array elements: %d\n", arrayLCM);

    return 0;
}