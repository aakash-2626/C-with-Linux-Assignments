/*
 * Program to print every third element of fibonacci series n times.
 * Command for Compilation -> gcc -o every_third_element_fibonacci every_third_element_fibonacci.c
 * Command for Execution -> ./every_third_element_fibonacci
 * Aakash Singla (1910990070), 04 August 2021
 * Assignment 5
 */

#include <stdio.h>

// function to print every third element of fibonacci series n times.
// param : int n : number of times to print
// return : void
void print_fibonacci(int n) {
    int position = 2;  // as we already stored first and second fibonacci numbers and will be calculating from third number in series
    int first = 1, second = 1;

    while(n > 0) {
        int third = first + second;
	position++;

	if(position == 3) {
	    printf("%d ", third);
	    position = 0;
	    n--;
	}

	first = second;
	second = third;
    }
}

int main() {
    int n = 0;
    printf("Enter the number of times to print:\n");
    scanf("%d", &n);

    print_fibonacci(n);
}
