/** 
 * NAME: pythagorean_triplet.cpp
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
 * USAGE: pythagorean_triplet
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/16/2010
 */


#include <iostream>
#include <cmath>
#include "../lib/number.h"

using namespace std;


int main(int argc, char* argv[]){
	int sum = 1000000;
	cout << pythagorean_triplet(sum) << endl;
	return 0;
}//main()
