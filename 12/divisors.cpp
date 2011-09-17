/** 
 * NAME: sum_of_primes.cpp
 * 
 * DESCRIPTION: 
 * General solution to Project Euler's Problem #6.
 * 
 * Question:
 * "A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 * a^2 + b^2 = c^2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * 
 * USAGE: sum_of_primes
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/16/2010
 */


#include <iostream>
#include <cstdlib>
#include "limits.h"
#include "../lib/number.h"

using namespace std;


unsigned long long int first_triangle_with_n_divisors(int limit){
	unsigned long long num;
	int count = 0;
	
	cout << "ULONG_LONG_MAX = " << ULONG_LONG_MAX << endl;
	for(unsigned long long int i = 1000000000; i < ULONG_LONG_MAX ; i++){
		if(is_triangular_number(i)){
			cout << i;
			cout << " is triangular";
			count = divisor_count(i);
			cout << " and has " << count << " divisors." << endl;
			if( count > limit ) { num = i; break; }
		}
	}
	return num;
}


int main(int argc, char* argv[]){
	int limit = 0;
	
	if(argc != 2){
		cerr << "USAGE: sum_of_primes <limit>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		limit = atoi(argv[1]);
	}//else - correct usage
	
	cout << first_triangle_with_n_divisors(limit) << endl;
	return 0;
}//main()
