/*
 * Program which returns the first location in the string1 where any character from the string2 occurs.
 * Command for Compilation -> gcc -o any any.c
 * Command for Execution -> ./any
 * Aakash Singla (1910990070), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

// function to find first occurence of any character from string s2 in string s1
// parameters - char* s1: first input string, char* s2:second input string
// return - int: position of first character matched.
int any(char* s1, char* s2) {
    for(int i = 0; s1[i] != '\0' ;i++) {
        for(int j = 0; s2[j] != '\0' ;j++) {
	    if(s1[i] == s2[j]) {
	        return i;
	    }
	}
    }

    return -1; 
}

int main () {
    char str[100];
    char t[100];

    printf("Enter the main string:\n");
    scanf("%[^\n]s",str);

    printf("Enter the substring to find:\n");
    scanf(" %[^\n]s",t);

    printf("\n%d\n", any(str,t));
    return 0;
}
