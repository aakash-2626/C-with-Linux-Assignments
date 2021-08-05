/*
 * Program to sort the array using Selection Sort using Recursion.
 * Command for Compilation -> gcc -o selection_sort_recursion selection_sort_recursion.c
 * Command for Execution -> ./selection_sort_recursion
 * Aakash Singla (1910990070), 04 August 2021 
 * Assignment 5
 */

#include <stdio.h>   

void swap(int a[], int i, int j);
int findMinimumIndex(int i, int a[], int size);
void selection_sort(int i, int a[], int size);

int main() {
    int size = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    int array[size];
    printf("\nEnter the elements of the array\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    selection_sort(0, array, size);

    printf("\nElements of the array after sorting :\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// sorts the array using selection sort using recursion
// param : int index : index of the array currently at which we are, int a[] : (array of integers), int size : size of array
// return : void
void selection_sort(int i, int a[], int size) {
    if(i == size - 1) {
        return;
    }

    int minIndex = findMinimumIndex(i, a, size);
    if(i != minIndex) {
        swap(a, i, minIndex);
    } 

    selection_sort(i + 1, a, size);
}


// finds the index of minimum element in the array starting from index i.
// param : int index : index of the array currently at which we are, int a[] : (array of integers), int size : size of array
// return : void
int findMinimumIndex(int i, int a[], int size) {
    if(i == size - 1) {
        return i;
    }

    int minOfRestArray = findMinimumIndex(i + 1, a, size);
    return a[i] < a[minOfRestArray] ? i : minOfRestArray;
}

// swaps the values in array at indexes i and j
// param : int a[] : (array of integers), int i : first index, int j : second index
// return : void
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
