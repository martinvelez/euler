/** 
 * NAME: prime.h
 * 
 * DESCRIPTION: 
 * Implements functions related to prime numbers.
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/13/2010
 */


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
