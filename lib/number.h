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
	if( num <= 1) {return false;}
	else if( num == 2 or num == 3) { return true; }
	else if( num % 2 == 0) { return false; }
	else if( num == 5 || num == 7) { return true; }
	else if( num % 3 == 0) { return false; }
	else {
		/**
		 * If n is composite, then it can be factored into two values, 
		 * at least one of which must be <= sqrt(n).
		 */
		long long int limit = (long long int) sqrt((double) num);
		//cout << "num = " << num << endl;
		//cout << "limit = " << limit << endl;
		long long int i = 5;
		while(i <= limit){
			if(num % i == 0){ return false;}
			if(num % (i+2) == 0){ return false;}
			i = i + 6;
		}
	}//else - start with 5 ( quicker method )
	return true;
}//is_prime()


//!Find the nth prime
unsigned long int find_prime(int pos){
	int count = 1;
	unsigned long int num = 2;
	
	if(pos == 1) { return num; }
	
	num = 3;
	while( count < pos){
			if(is_prime(num)) { count++; }
			if( count != pos ) { num = num + 2; }
	}
	
	return num;
}//find_prime

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


//!Find the product of the pythagorean triplet {a,b,c} where a+b+c=1000.
unsigned long int pythagorean_triplet(int sum){
	int temp_sum = 0;
	unsigned long int product = 0;

	int limit = sum/3;
	for(int n = 2; n < limit; n++){
		if(temp_sum == sum) { break; }
		for(int m = 1; m < n; m++){
			int a = pow(n,2) - pow(m,2);
			int b = 2*m*n;
			int c = pow(n,2) + pow(m,2);
			temp_sum = a + b + c;
			//cout << a << ", " << b << ", " << c << ", sum = " << temp_sum << endl;
			if(temp_sum == sum) { product = a * b * c; break; }
		}
	}
	return product;
}
