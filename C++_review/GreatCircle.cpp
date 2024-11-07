#include <iostream>
#include <cmath>
int main(int argc, char **argv)
{
	float x1, y1, x2, y2, distance;

	x1 = atof(argv[1]); 
	y1 = atof(argv[2]);
	x2 = atof(argv[3]);
	y2 = atof(argv[4]);  

	distance = ((sin(x1) * sin(x2)) + (cos(x1) * cos(x2) * (cos(y1 - y2))));

	std::cout << distance << std::endl;

	return 0; 
}