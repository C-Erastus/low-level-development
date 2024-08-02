#include <iostream>
#include <stddef.h>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main()
{
	double r = 5.0;
	double circle;  

	circle = 2 * PI * r; // circle = 2 * 3.14159 * r;
	cout << circle << NEWLINE;// cout << circle << '\n';

	return 0;
}