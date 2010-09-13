/* Name: prime_factorization.cpp
 * Description: Find the largest prime factor of any number. 
 * General solution to Project Euler's Problem #3.
 * "The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?"
 * Usage: prime_factorization <integer>
 * Author: Martin Velez
 * Date: 09/13/2010
 */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool is_prime(long long int num){
	if( num < 1 || ((num % 2 == 0) && num != 2)){ return false; }
	if (num == 2){ return true; }
	for(long long int i = 3; i < num/2; i+=2){
		if(num % i == 0){ return false; }
	}
	return true;
}//is_prime()


int main(int argc, char* argv[]){
	long long int num;
	long long int largest_prime_factor = 0;
	
	if(argc != 2){
		cerr << "usage: prime_factorization <integer>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		num = atoll(argv[1]); 
	}//else - correct usage
	
	if(num % 2 == 0){ largest_prime_factor = 2; }
	for(long long int i = 3; i < num/2; i+=2){
		if(num % i == 0){
			if(is_prime(i)){ largest_prime_factor = i; }
		}//if - is prime, then test
	}//for
	
	cout << largest_prime_factor << endl;
	return 0;
}//main()
