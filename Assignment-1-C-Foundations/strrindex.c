/*
 * Program which returns the position of the rightmost occurrence of t in s , or - 1 if there is none.
 * Command for Compilation -> gcc -o strrindex strrindex.c
 * Command for Execution -> ./strrindex
 * Aakash Singla (1910990070), 02/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>

// function to find position of rightmost occurence of string t in string s
// parameters - char* s: first input string, char* t: second input string
// return - int: right most position of t in s.
int strrindex (char*s, char* t) {
    int found = 0;
    int position = -1;

    for(int i = 0; s[i] != '\0'; i++) {
	found = 0;
        if(s[i] == t[0]) {
	    for(int j = 1; t[j] != '\0'; j++) {
	        if(s[i + j] == '\0' || s[i + j] != t[j]) {
		    found = 1;
		    break;
		}
	    }
	    if(found == 0) {
	        position = i;
	    }
	}
    }

    return position;
}

int main () {
    char str[100];
    char t[100];

    printf("Enter the main string:\n");
    scanf("%[^\n]s",str);

    printf("Enter the substring to find:\n");
    scanf(" %[^\n]s",t);

    printf("\nRightMost Occurrence of given substring is %d\n", strrindex(str,t));
    return 0;
}
