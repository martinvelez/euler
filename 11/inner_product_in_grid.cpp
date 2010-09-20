/** 
 * NAME: inner_product_in_grid.cpp
 * 
 * DESCRIPTION: 
 * General solution to Project Euler's Problem #11.
 * 
 * USAGE: inner_product_in_grid
 * 
 * AUTHOR: Martin Velez
 * 
 * DATE: 09/19/2010
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;


long int inner_product_in_grid(vector <vector<int> > grid){
	long int product = 0;
	
	for(unsigned int i = 0; i < grid.size(); i++){
		for(unsigned int j = 0; j < grid[i].size(); j++){
			long int temp_product = 1;
			
			if(j <= grid[i].size()-4){
				temp_product = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
			}//go left
			if( (j <= grid[i].size()-4) && (i <= grid.size()-4) ){
				temp_product = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
			}//go down-left			
			if(i <= grid.size()-4){
				temp_product = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
			}//go down
			if( ((3 <= j) && (j <= 19)) && (i <= grid.size()-4) ){
				temp_product = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
			}//go down-right
			if(temp_product > product) { product = temp_product; }
		}//for - column
	}//for -row
	
	return product;
}//inner_product_in_grid


int main(int argc, char* argv[]){
	ifstream datafile;  //file which contains grid
	vector< vector<int> > grid;  //grid
	
	if(argc != 2){
		cerr << "USAGE: inner_product_in_grid <datafile>" << endl;
		return EXIT_FAILURE;
	}//if - incorrect usage
	else{ 
		datafile.open(argv[1]);
		if (!datafile){
			cout << "Error in openening file";
			return EXIT_FAILURE;
		}
	}//else - correct usage
	
	string line;
	while( getline(datafile, line) ){
		//cout << line << endl;
		vector<int> temp_vector;
		for(unsigned int i = 0; i <= line.length() - 2; i+=3){
				//cout << line.substr(i, 2).c_str() << endl;
				temp_vector.push_back( atoi(line.substr(i, 2).c_str()) );
		}//for - parse line
		grid.push_back( temp_vector );
	}//while
	
	cout << inner_product_in_grid(grid) << endl;
	
	return 0;
}//main()
