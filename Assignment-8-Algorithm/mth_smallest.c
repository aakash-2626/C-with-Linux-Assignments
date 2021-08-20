/*
 * Program to find Mth smallest number in an unsorted array.
 * Command for Compilation -> gcc -o mth_smallest mth_smallest.c
 * Command for Execution -> ./mth_smallest
 * Aakash Singla, (1910990070), 19/08/2021
 * Assignment 8 - Algorithm
 */
 
#include <stdio.h>

// swaps the values in array arr at indexes i and j.
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// paritions the array arr from indexes left to right.
int partition(int* arr, int left, int right) {
    int num = arr[right];
    int ind = left - 1;
    
    for(int i = left; i < right; i++) {
        if(arr[i] <= num) {
            swap(arr, ++ind, i);
        }
    }
    
    swap(arr, ind + 1, right);
    return ind + 1;
}

// helper function to find the mth smallest number in array arr.
int findMthSmallest(int* arr, int left, int right, int M) {
    if(left == right) {
        return arr[left];
    }
    
    int pos = partition(arr, left, right);
    int count = pos - left + 1;
    if(count == M) {
        return arr[pos];
    } else if(count > M) {
        return findMthSmallest(arr, left, pos - 1, M);
    } else {
        return findMthSmallest(arr, pos + 1, right, M - count);
    }
}

// finds the mth smallest number in array arr.
int mthSmallest(int* arr, int size, int M) {
    return findMthSmallest(arr, 0, size - 1, M);
}

int main() {
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    
    printf("Enter the elements of the array:\n");
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int M;
    printf("Enter the value of M:\n");
    scanf("%d", &M);
    
    printf("\nAnswer is %d\n", mthSmallest(arr, n, M));

    return 0;
}

