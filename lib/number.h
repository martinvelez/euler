/** 
 * NAME: number.h
 * 
 * DESCRIPTION: 
 * Implements functions related to numbers.
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/13/2010
 */

#include <cmath>

using namespace std;

/**
 * Tests if a given number (num) is prime.
 */
bool is_prime(long long int num){
	if( num < 1 || ((num % 2 == 0) && num != 2)) return false;
	if (num == 2) return true;
	
	/**
	 * If n is composite, then it can be factored into two values, 
	 * at least one of which must be <= sqrt(n).
	 */
	for(long long int i = 3; i < ((long long int) sqrt((double) num) + 1); i+=2){
		if(num % i == 0) return false;
	}//for
	return true;
}//is_prime()


/**
 * reverse an integer expressed in base 10
 */
unsigned long int reverse(unsigned long int num){
	unsigned long int reversed_num = 0;
	
	while( num > 0){
		reversed_num = 10*reversed_num + (num % 10);
		num = num / 10;
	}
	
	return reversed_num;
}//reverse()


/**
 * Check if a number is palindromic.
 */
bool is_palindromic(unsigned long int num){
	return num == reverse(num);
}//is_palindromic()


//!Find the sum of the squares of the numbers in the range (inclusive)
unsigned long int sum_of_squares(int low, int high){
	unsigned long int sum = 0;
	if(low == 1){
		//!Sum of the first n square numbers = (n(n+1)(2n+1))/6
		sum = (high * (high + 1) * ((2 * high) + 1))/6;
	}//if - first n square numbers (quicker method)
	else{
		for(int i = low; i <= high; i++){ sum = sum + pow(i,2); }
	}//else - any range
	return sum;
}//sum_of_squares


//!Find the square of the sume of the integers in the range (inclusive)
unsigned long int square_of_sum(int low, int high){
	unsigned long int sum = 0;
	if(low == 1){
		//!Sum of first n numbers = (n(n+1)) / 2
		sum = pow( (high * (high + 1)) / 2, 2);
	}//if - first n numbers (quicker method)
	else{
		for(int i = low; i <= high; i++){ sum = sum + i; }
		cout << "square_of_sum = " << sum << endl;
		sum = pow(sum, 2);
	}//else - any range
	return sum;
}//square_of_sum
