#include<stdio.h>

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return 1; // Return 1 if the target is found
        }
    }
    // Return 0 if the target is not found
    return 0;
}
int main(){
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

    // get target value fro search
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if(result != 0){
        printf("Element found.\n");
    }
    else{
        printf("Element not found.\n");
    }

    return 0;
}