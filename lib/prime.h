
bool is_prime(long long int num){
	if( num < 1 || ((num % 2 == 0) && num != 2)){ return false; }
	if (num == 2){ return true; }
	for(long long int i = 3; i < num/2; i+=2){
		if(num % i == 0){ return false; }
	}
	return true;
}//is_prime()
