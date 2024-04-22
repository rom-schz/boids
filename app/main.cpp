#include <iostream>

#include "boid.hpp"
#include "flock.hpp"
#include "raylib.h"

int main(int argc, char** argv){

	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Boids - 2d simulation");

	SetTargetFPS(60);

	Flock flock = Flock();

	Boid boid1 = Boid(0, 0, 10, 10);
	Boid boid2 = Boid(100, 100, 10, -10);

	flock.addBoid(boid1);
	flock.addBoid(boid2);

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		flock.render(screenWidth, screenHeight);
		flock.updateVel();
		flock.update(screenWidth, screenHeight);

		EndDrawing();
	}

	return EXIT_SUCCESS;
}
