/** 
 * NAME: find_prime_7.cpp
 * 
 * DESCRIPTION: 
 * General solution to Project Euler's Problem #7.
 * 
 * Question:
 * "By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
 * we can see that the 6th prime is 13.
 * What is the 10001st prime number?"
 * 
 * Answer: _________
 * 
 * USAGE: find_prime_7 <pos>
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/16/2010
 */


#include <iostream>
#include <cstdlib>
#include "../lib/number.h"


using namespace std;


int main(int argc, char* argv[]){
	int pos; 	//nth prime
	
	if(argc != 2){
		cerr << "USAGE: find_prime_7 <pos>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		pos = atoi(argv[1]);
		if( 1 > pos){
			cerr << "USAGE: find_prime_7 <pos>" << endl;
			cerr << "pos must be a positive integer" << endl;
			return EXIT_FAILURE;
		}
	}//else - correct usage
	
	cout << find_prime(pos) << endl;
	return 0;
}//main()
