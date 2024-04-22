#include <iostream>

#include "boid.hpp"
#include "flock.hpp"

int main(int argc, char** argv){

	Flock flock = Flock();

	Boid boid1 = Boid(0, 0, 1, 1);
	Boid boid2 = Boid(1, 1, 1, -1);

	flock.addBoid(boid1);
	flock.addBoid(boid2);

	std::cout << "Hello World!" << std::endl;
	return EXIT_SUCCESS;
}
