/*
 * Program to multiply two matrices.
 * Command for Compilation -> gcc -o multiply_matrices multiply_matrices.c
 * Command for Execution -> ./multiply_matrices
 * Aakash Singla (1910990070), 27 July 2021
 * Assignment 1 - C Foundations
 */

#include <stdio.h>

// to multiply two matrices
void multiply_matrices(int size, int (*arr1)[size], int (*arr2)[size]) {
    int multiply[size][size];
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
	    multiply[i][j] = 0;
	    for(int k = 0; k < size; k++) {
	        multiply[i][j] += (arr1[i][k] * arr2[k][j]);
	    }
	}
    }

    printf("\nMatrix after multiplying the matrices\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", multiply[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 0;
    printf("Enter the size of the arrays\n");
    scanf("%d", &size);

    int arr1[size][size];
    printf("\nEnter the elements of the first array\n");
    for(int i = 0; i < size; i++) {
	for(int j = 0; j < size; j++) {
	    scanf("%d", &arr1[i][j]);
	}
    }

    int arr2[size][size];
    printf("\nEnter the elements of the second array\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    
    multiply_matrices(size, arr1, arr2);
    return 0;
}
