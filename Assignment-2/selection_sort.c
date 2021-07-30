/*
 * Program to analyze Runtime Complexity of Selection Sort.
 * Command for Compilation -> gcc -o selection_sort selection_sort.c
 * Command for Execution -> ./selection_sort.c
 * Aakash Singla (1910990070), 29 July 2021 
 * Assignment 2
 */

#include <stdio.h>   
#include <stdlib.h>      // for rand() function
#include <sys/time.h>    // for gettimeofday() function

void generateRandomInput(int a[], int size);
void generateAscendingInput(int a[], int size);
void generateDescendingInput(int a[], int size);
void swap(int a[], int i, int j);
void selection_sort(int a[], int size);
void generate_report(int initial_input_size, int increment_by);

int main() {
    
    int initial_input_size = 8000;   // initial size of array
    int increment_by = 4000;         // value by which size needs to be incremented each time
    
    printf("starting");
    generate_report(initial_input_size, increment_by);

    printf("\n"); 
}

// prints the time taken by selection sort to complete at different sizes and different types of values in the array
// param : int initial_input_size : initial array size, int increment_by : value by which size needs to be incremented each time
// return : void
void generate_report(int initial_input_size, int increment_by) {
    struct timeval te;
    
    for(int i = 0; i < 7; i++) {
        int size = initial_input_size + increment_by * i;
	int a[size];

	//generateRandomInput(a, size);
	//generateAscendingInput(a, size);
	generateDescendingInput(a, size);

	gettimeofday(&te, NULL);
	long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
	selection_sort(a, size);
	gettimeofday(&te, NULL);
	long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

	printf("\n%lld", end - start);
    }
}  

// generates array with random numbers
// param : int a[] : (array of integers), int size : size of array
// return : void
void generateRandomInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = rand() % size + 1;
    }
}

// generates array with ascending numbers
// param : int a[] : (array of integers), int size : size of array
// return : void
void generateAscendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = i + 1;
    }
}

// generates array with descending numbers
// param : int a[] : (array of integers), int size : size of array
// return : void
void generateDescendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = size - i + 1;
    }
}

// sorts the array using selection sort
// param : int a[] : (array of integers), int size : size of array
// return : void
void selection_sort(int a[], int size) {
    for(int i = 0; i < size - 1; i++) {
	int minIndex = i;
        for(int j = i + 1; j < size; j++) {
	    if(a[j] < a[minIndex]) {
		minIndex = j;
	    }
	}

	if(i != minIndex) {
	    swap(a, i, minIndex);
	}
    }
}

// swaps the values in array at indexes i and j
// param : int a[] : (array of integers), int i : first index, int j : second index
// return : void
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

