#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // define array
    int n;

    // get the input
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Perform Bubble Sort
    bubbleSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
