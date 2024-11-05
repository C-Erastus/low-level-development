#include <iostream>

int main(int argc, char **argv){

	bool val;

	if((argv[1] < argv[2]) && (argv[2] < argv[3]))
		std::cout << "true" << std::endl; 
	else if ((argv[1] > argv[2]) && (argv[2] > argv[3]))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	return 0;
}