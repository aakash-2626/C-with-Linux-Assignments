/**
 * Program to count Inversion Count for an array.
 * Command for Compilation -> gcc -o inversion_count inversion_count.c
 * Command for Execution -> ./inversion_count
 * Aakash Singla (1910990070), 12 August 2021
 * Assignment 7 - Sorting
*/

#include <stdio.h>

// merges the array from (low to mid) and (mid + 1 to high)
// param : arr - array of pointers   
// return : inversion count from low to high
int merge(int* arr[], int low, int mid, int high) {
    int temp[high - low + 1];
    int inversion_count = 0;
    
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high) {
        if(*arr[i] <= *arr[j]) {
            temp[k++] = *arr[i++];
        }
        else {
            inversion_count += (mid - i + 1);
            temp[k++] = *arr[j++];
        }
    }
    
    while(i <= mid) {
        temp[k++] = *arr[i++];
    }
    
    while(j <= high) {
        temp[k++] = *arr[j++];
    }
    
    i = low, j = 0;
    while(i <= high) {
        *arr[i++] = temp[j++];
    }
    
    return inversion_count;
}

// counts the inversions for arr
// param : arr - array of pointers   n - size of array
// return : inversion count
int count_inversions_helper(int* arr[], int low, int high) {
    int inversion_count = 0;
    if(low < high) {
        int mid = low + (high - low) / 2;
        inversion_count += count_inversions_helper(arr, low, mid);
        inversion_count += count_inversions_helper(arr, mid + 1, high);
        
        inversion_count += merge(arr, low, mid, high);
    }
    
    return inversion_count;
}

// counts the inversions for arr
// param : arr - array of pointers   n - size of array
// return : inversion count
int count_inversions(int* arr[], int n) {
    return count_inversions_helper(arr, 0, n - 1);
}

int main() {
    int n = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    
    printf("\nEnter the elements:\n");
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr[n];
    
    for (int i = 0; i < n; i++) {
      ptr[i] = &arr[i]; /* assign the address of integer. */
   }
   
    printf("\nInversion Count of this array is %d\n", count_inversions(ptr, n));

    return 0;
}

