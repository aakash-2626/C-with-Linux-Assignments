/*
 * Program to print pyramid with given number of steps.
 * Command for Compilation -> gcc -o print_pyramid print_pyramid.c
 * Command for Execution -> ./print_pyramid
 * Aakash Singla (1910990070), 27 July 2021 
 * Assignment 1 - C Foundations
 */

#include <stdio.h>

void printPyramid(int steps) {
    for(int i = 1; i <= steps; i++) {
        for(int j = 1; j <= steps - i; j++) {
            printf(" ");
        }

        for(int j = 1; j <= i; j++) {
            printf("# ");
        }

	printf("\n");
    }
}

int main() {
    int steps = 0;
    printf("Enter the number of steps\n");
    scanf("%d", &steps);

    printPyramid(steps);
}
