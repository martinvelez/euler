/** 
 * NAME: sum_6.cpp
 * 
 * DESCRIPTION: 
 * General solution to Project Euler's Problem #6.
 * 
 * Question:
 * "The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural 
 * numbers and the square of the sum is 3025 - 385 = 2640."
 * 
 * Answer: 25164150
 * 
 * USAGE: sum_6 <low> <high>
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/16/2010
 */


#include <iostream>
#include <cstdlib>
#include "../lib/number.h"


using namespace std;


/**
 * Find the largest palindromic number which is a multiple of two three-digit
 * numbers.
 */
unsigned long int difference_of_squares(int low, int high){
	return square_of_sum(low, high) - sum_of_squares(low, high);
}//largest_palindrome


int main(int argc, char* argv[]){
	int low; 	//low value of range
	int high;	//high value of range
	
	if(argc != 3){
		cerr << "USAGE: sum_6 <low> <high>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		low = atoi(argv[1]);
		high = atoi(argv[2]);
	}//else - correct usage
	
	cout << difference_of_squares(low, high) << endl;
	return 0;
}//main()
