/*
 * Program that deletes each character in first string that matches any character in the second string.
 * Command for Compilation -> gcc -o squeeze squeeze.c
 * Command for Execution -> ./squeeze
 * Aakash Singla (1910990070), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

// checks whether given string contains the given character or not
// parameters - char* str: input string, char ch: input character to find
// return - int: return 1 if ch found, else return 0
int contains(char* str, char ch) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch) {
	    return 1;
	}
    }

    return 0;
}

// function to delete each character in string s1 that matches any character in string s2
// parameters - char* s1: first input string, char* s2: second input string
// return - void
void squeeze(char* s1, char* s2) {
    int index = 0;
    for(int i = 0; s1[i] != '\0'; i++) {
        if(contains(s2, s1[i]) == 0) {
	    s1[index++] = s1[i];
	}
    }

    s1[index] = '\0';
}

int main () {
    char str1[100];
    char str2[100];

    printf("Enter the first string\n");
    scanf("%[^\n]s", str1);

    printf("Enter the second string\n");
    scanf(" %[^\n]s", str2);

    squeeze(str1, str2);

    printf("\nOutput: %s\n", str1);
    return 0;
}
