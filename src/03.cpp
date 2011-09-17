/** 
 * NAME: lpf_3.cpp
 * 
 * DESCRIPTION: 
 * Find the largest prime factor of any number.
 *  
 * General solution to Project Euler's Problem #3.
 * "The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?"
 * 
 * USAGE: lpf_3 <integer>
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/13/2010
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "float.h"
#include "../lib/prime.h"


using namespace std;


/**
 * Finds the largest prime factor a given number.
 */
long long int largest_prime_factor(long long int num){
	long long int largest_prime_factor = 0;
	int first_prime = 2;
	
	if(num % first_prime == 0){ largest_prime_factor = first_prime; }
	
	for(long long int i = 3; i < ((long long int) sqrt( (double) num) + 1); i+=2){
		if(num % i == 0){
			if(is_prime(i)){ largest_prime_factor = i; }
		}//if - divides num, then test if prime
	}//for
	
	if(largest_prime_factor == 0) return num;
	
	return largest_prime_factor;
}//largest_prime_factor()


int main(int argc, char* argv[]){
	long long int num;
	
	if(argc != 2){
		cerr << "USAGE: lpf_3 <integer>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		num = atoll(argv[1]);
		if (num > DBL_MAX ){
			cerr << "USAGE: lpf_3 <integer>" << endl;
			cerr << "<integer> must be less than " << DBL_MAX << endl;
			return EXIT_FAILURE;
		}
	}//else - correct usage
		
	cout << largest_prime_factor(num) << endl;
	
	return 0;
}//main()
