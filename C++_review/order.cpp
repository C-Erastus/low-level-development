#include <iostream>

int main(int argc, char **argv){

	bool val;

	if(( atoi(argv[1]) < atoi(argv[2])) && (atoi(argv[2]) < atoi(argv[3]))){
		std::cout << "true" << std::endl; 
		std::cout << "part 1" << std::endl;
	}
	else if ((atoi(argv[1]) > atoi(argv[2])) && (atoi(argv[2]) > atoi(argv[3]))){
		std::cout << "true" << std::endl;
		std::cout << "part 2" << std::endl;
	}
	else
		std::cout << "false" << std::endl;

	return 0;
}