/*
 * Program to swap two numbers without using third variable.
 * Command for Compilation -> gcc -o swap_numbers swap_numbers.c
 * Command for Execution -> ./swap_numbers
 * Aakash Singla (1910990070), 27 July 2021 
 * Assignment 1 - C Foundations
 */

#include <stdio.h>

int main() {
    int first_number = 0, second_number = 0;

    // Taking the input
    printf("Enter First Number\n");
    scanf("%d", &first_number);
    printf("Enter Second Number\n");
    scanf("%d", &second_number);

    // swapping the variables
    first_number = first_number ^ second_number;
    second_number = first_number ^ second_number;
    first_number = first_number ^ second_number;

    printf("\nNumbers after swapping are %d, %d", first_number, second_number);	    
    return 0;
}
