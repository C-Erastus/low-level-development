#include <iostream>

int main(int argc, char **argv){

	std::cout << "Hi ";

	for(int i = argc-1; i >= 1; i--){
		std::cout << argv[i]<< " ";
	}
	std::cout << "\n";

	return 0;
}