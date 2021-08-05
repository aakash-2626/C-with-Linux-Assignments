/*
 * Program to reverse the given 1D array.
 * Command for Compilation -> gcc -o reverse_array  reverse_array.c
 * Command for Execution -> ./reverse_array
 * Aakash Singla (1910990070), 27 July 2021
 * Assignment 1 - C Foundations
 */

#include <stdio.h>

// to swap the values at indexes i and j in arr
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// to reverse the array
void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        swap(arr, i, size - i - 1);
    }
}

int main() {
    int size = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements of the array\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printf("\nArray after reversing: \n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

}

