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
#include <sstream>
#include <string>

using namespace std;

/**
 * reverse a string and return a copy
 */
string reverse(string str){
	string rev_str;
	string::reverse_iterator rit;
	for(rit=str.rbegin(); rit < str.rend(); rit++){
		rev_str.push_back(*rit);
	}
	return rev_str;
}//reverse


/**
 * Check if a number is palindromic.
 */
bool is_palindromic(unsigned long num){
	/**
	 * Convert integer to string
	 */
	string num_str;
	stringstream out_ss;
	out_ss << num;
	num_str = out_ss.str();

	return num_str == reverse(num_str);
}//is_palindromic()


int main(int argc, char* argv[]){
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
	
	cout << largest_palindrome << endl;
	return 0;
}//main()
