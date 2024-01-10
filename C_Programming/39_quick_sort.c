#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot element in its correct position)
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two halves and get the index of the pivot
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    // Define array
    int n;

    // Get the input
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Perform QuickSort
    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
