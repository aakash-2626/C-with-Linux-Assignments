/*
 * Program to print n numbers in Fibonacci series that are even.
 * Command for Compilation -> gcc -o even_fibonacci even_fibonacci.c
 * Command for Execution -> ./even_fibonacci
 * Aakash Singla, (1910990070), 19/08/2021
 * Assignment 8 - Algorithm
 */

#include<stdio.h>

// function to find the nth even fibonacci number.
// param : int n, long* dp - memoization array
// return : long : nth even fibonacci number
long nth_even_fibonacci(int n, long* dp) {
    if(n == 1) {
        return 2;
    }
    
    if(n == 2) {
        return 8;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    return dp[n] = 4 * nth_even_fibonacci(n - 1, dp) + nth_even_fibonacci(n - 2, dp);
}

int main() {
    int n;
    printf("Enter the number of even numbers in fibonacci series to print:\n");
    scanf("%d", &n);
    printf("\n");
    
    long dp[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        printf("%ld ", nth_even_fibonacci(i, dp));
    }
    printf("\n");
    
    return 0;
}
