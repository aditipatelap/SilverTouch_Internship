#include<stdio.h>

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
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

    int result = binarySearch(arr, n, target);

    if(result != -1){
        printf("Element found at index %d\n", result);
    }
    else{
        printf("Element not found in the array.\n");
    }

    return 0;
}