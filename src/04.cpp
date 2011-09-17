/** 
 * NAME: palindromic_4.cpp
 * 
 * DESCRIPTION: 
 * Solution to Project Euler's Problem #4.
 * "A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of two 2-digit numbers is 
 * 9009 = 91 * 99.
 * Find the largest palindrome made from the product of two 3-digit numbers."
 * 
 * USAGE: palindromic_4 <integer>
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/13/2010
 */


#include <iostream>
#include "../lib/number.h"


using namespace std;


/**
 * Find the largest palindromic number which is a multiple of two three-digit
 * numbers.
 */
unsigned long int largest_palindrome(){
	unsigned long int largest_palindrome = 0;
	
	for(unsigned long int i = 999; i >= 100; i--){
		for(unsigned long int j = 999; j >= 100; j--){
			//cout << i << " " << j << " = " << (i*j) << endl;
			if( (i*j) < largest_palindrome ) { break; }
			if(is_palindromic(i * j)){
				largest_palindrome = i * j;
				break;
			}//if
		}//for
	}//for
	
	return largest_palindrome;
}//largest_palindrome


int main(int argc, char* argv[]){
	cout << largest_palindrome() << endl;
	return 0;
}//main()
