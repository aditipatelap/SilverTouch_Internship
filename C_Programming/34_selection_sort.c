#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i+1; i < n; j++)
        {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    // Perform Selection Sort
    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}