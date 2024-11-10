#include <iostream>

int main(int argc, char **argv)
{

	int n = atoi(argv[1]);
	int bits = 0;

	if (n < 1) {
		std::cout << "Illegal input" << std::endl; 
		exit(1);
	}
	while (n > 0) {
		bits++;
		n = n/2;
	}

	std::cout << bits << std::endl;
	return 0;
}