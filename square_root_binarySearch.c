/**
 * Program which computes square root of an integer without using any inbuilt functions.
 *
 * Command for Compilation : gcc -o square_root_binarySearch square_root_binarySearch.c
 * Command for Execution : ./square_root_binarySearch
 *
 * @Aakash Singla (1910990070) 18/07/2021
 * Assignment - 1
 */

#include <stdio.h>

double square_root_binary_search(int, int);

int main() {
    // Number and the precision
    int number = 0;
    int precision = 0;

    printf("Enter number\n");
    scanf("%d",&number);
    printf("Enter precision\n");
    scanf("%d",&precision);

    double result = square_root_binary_search (number, precision);

    printf("%.*lf",precision, result);
}

/**
 * Function computes square root of an integer using binary search.
 *
 * Parameters:
 * number : integer number whose square root need to compute
 * precision : int precision
 *
 * Returns square root in double type
 */
double square_root_binary_search (int number, int precision) {
    // calculating the difference
    double difference = 1;
    for (int i = 0; i < precision; i++) {
        difference /= 10;
    }

    // bounds for calculating square root
    double lower_limit = 0;
    double upper_limit = number;

    // search for square root
    while ((upper_limit - lower_limit) > difference) {
        double mid = lower_limit + (upper_limit - lower_limit) / 2;
	
        // if square root of mid is less than equal to number, move to right side
	if (mid * mid <= number) {
	    lower_limit = mid;
	} else {
	    upper_limit = mid;
	}
    }

    return lower_limit;
} 
