/*
 * Program to find the count of the number of vowels and consonants in the given string.
 * Command for Compilation -> gcc -o count_vowels_consonants  count_vowels_consonants.c
 * Command for Execution -> ./count_vowels_consonants
 * Aakash Singla (1910990070), 27 July 2021
 * Assignment 1 - C Foundations
 */

#include <stdio.h>

// to check if given ch is vowel or not
int isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') == 1 ? 1 : 0;
}


// to count the number of vowels and consonants
void countVowelsConsonants(char str[]) {
    int vowels = 0, consonants = 0;  // to maintain the count 
    for(int i = 0; str[i] != '\0'; i++) {
	if(isVowel(str[i]) == 1) {
	    vowels++;
	}
	else {
	    consonants++;
	}
    }

    printf("Vowels = %d, Consonants = %d", vowels, consonants); 
}

int main() {
    char str[100];
    printf("Enter the String\n");
    scanf("%[^\n]s", str);  // read string

    countVowelsConsonants(str);
    return 0;
}
	
