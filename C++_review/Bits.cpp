#include <iostream>

int main(int argc, char **argv){

	int n = atoi(argv[1]);
	int bits = 0;

	if (n < 0)
		std::cout << "Illegal input" << std::endl; 
	else if (n > 0 ){
		bits += 1;
	}
	else
		bits = 0;

	while(n > 1){
		bits += (n % 2); 
		n = n/2;
	}

	std::cout << bits << std::endl;
	return 0;
}