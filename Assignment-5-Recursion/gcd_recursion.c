/*
 * Program to find GCD of two numbers..
 * Command for Compilation -> gcc -o gcd_recursion gcd_recursion.c
 * Command for Execution -> ./gcd_recursion
 * Aakash Singla (1910990070), 04 August 2021 
 * Assignment 5
 */

#include <stdio.h>

// returns the gcd of two given numbers
// param : int num1 : first number, int num2 : second number
// return : int : gcd of num1 and num2
int findGCD(int num1, int num2) {
    if(num1 == 0) {
        return num2;
    }

    return findGCD(num2 % num1, num1);
}

int main() {
    int num1 = 0, num2 = 0;
    printf("Enter the first number:\n");
    scanf("%d", &num1);

    printf("Enter the second number:\n");
    scanf("%d", &num2);

    int gcd = findGCD(num1, num2);
    printf("\nGCD of %d and %d is %d", num1, num2, gcd);
}


