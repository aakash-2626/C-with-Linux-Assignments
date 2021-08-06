/*
 * Program to converts a string of hexadecimal digits into its equivalent integer value.
 * Command for Compilation -> gcc -o htoi htoi.c -lm   // -lm as pow() function does not work directly in linux
 * Command for Execution -> ./htoi
 * Aakash Singla (1910990070), 03/08/2021
 * Assignment 1 (C Foundations)
 */

#include<stdio.h>
#include<math.h>

// calculate length of string
// parameters - char* str: input string
// return - int: length of string
int string_length(char* str) {
    int i = 0;
    for(; str[i] != '\0'; i++);

    return i;
}

// calculates integer value of given hexadecimal number
// parameter - char* str: input string
// return - int: integer value of hexadecimal string
int htoi(char* str) {
    int value = 0;
    int str_length = string_length(str);

    for(int i = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) ? 2 : 0; i < str_length ; i++) {
	int data = 0;
	if(str[i] >= 97 && str[i] <= 102) {
	    data = str[i] - 87;
	}
	else if(str[i] >= 65 && str[i] <= 90) {
	    data = str[i] - 55;
	}
	else {
	    data = str[i] - 48;
	}

        value += data * (pow(16,str_length - i - 1)); 
    }

    return value;
}

int main () {
    char hexa_str[100];

    printf("Enter the hexadecimal number:\n");
    scanf("%[^\n]s", hexa_str);

    printf("\nInteger Value of the given number is %d\n", htoi(hexa_str));
    return 0;
}
