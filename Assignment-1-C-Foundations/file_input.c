/*
 * Program to print all input lines that are longer than 80 characters.
 * Command for Compilation -> gcc -o file_input file_input.c
 * Command for Execution -> ./file_input
 * Aakash Singla, (1910990070), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

// function to calculate length of string
// parameters - char* str : input string
// return - int : length of string
int string_length(char* str) {
    int i = 0;
    for(; str[i] != '\0'; i++);

    return i;
}

// function to print all the lines in file which are longer than 80 characters.
// return void
void print_lines() {
    FILE* file = fopen("./input.txt", "r"); // input.txt is the input file.
    char str[1000];

    while(fscanf(file, " %[^\n]s", str) != EOF) {
        if(string_length(str) >= 80) {
            printf("%s\n\n",str);
        }
    }

    fclose(file);
}

int main () {
    print_lines();
    return 0;
}
