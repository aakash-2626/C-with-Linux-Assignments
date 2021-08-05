/*
 * Program to implement the Tower of Hanoi Function.
 * Command for Compilation -> gcc -o tower_of_hanoi tower_of_hanoi.c
 * Command for Execution -> ./tower_of_hanoi
 * Aakash Singla (1910990070), 04 August 2021 
 * Assignment 5
 */

#include <stdio.h>

// implements the Tower of Hanoi
// param : int n : number of disks, char from : rod to transfer disks from, char to : rod to transfer disks to, char aux : helper rod
// return : int : total number of movements required to implement tower of hanoi
int tower_of_hanoi(int n, char from, char to, char aux) {
    if(n == 0) {
        return 0;
    }

    int movements = 0;
    
    movements += tower_of_hanoi(n - 1, from, aux, to);
    
    printf("%c to %c\n", from, to);
    movements++;

    movements += tower_of_hanoi(n - 1, aux, to, from);

    return movements;
}

int main() {
    int num = 0;
    printf("Enter the number of disks:\n");
    scanf("%d", &num);

    int movements = tower_of_hanoi(num, 'A', 'C', 'B');
    printf("Total movements required = %d", movements);
}

