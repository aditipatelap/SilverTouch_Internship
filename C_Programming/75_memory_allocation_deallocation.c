#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray;
    int arraySize;

    // Get the size of the dynamic array from the user
    printf("Enter the size of the dynamic array: ");
    scanf("%d", &arraySize);

    // Allocate memory for the dynamic array using malloc
    dynamicArray = (int *)malloc(arraySize * sizeof(int));

    // Check if memory allocation was successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Input values into the dynamic array
    printf("Enter %d integers for the dynamic array:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Display the values in the dynamic array
    printf("Dynamic Array Values: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Deallocate the memory using free
    free(dynamicArray);

    // Set the pointer to NULL to avoid using it after deallocation
    dynamicArray = NULL;

    return 0;
}