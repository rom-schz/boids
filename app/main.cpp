#include <iostream>

#include "boid.hpp"
#include "flock.hpp"
#include "raylib.h"

int main(int argc, char** argv){


	// RayLib stuff
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Boids - 2d simulation");
	SetTargetFPS(60);


	// Initialize the simulation with a flock and some boids
	Flock flock = Flock();

	Boid boid1 = Boid(screenWidth/2, screenHeight/2, 10, 10);
	Boid boid2 = Boid(screenWidth/2 + 100, screenHeight/2 + 100, -10, -10);

	flock.addBoid(boid1);
	flock.addBoid(boid2);



	// Main loop
	while(!WindowShouldClose()) {

		// Rendering
		BeginDrawing();

		ClearBackground(RAYWHITE);

		flock.render(screenWidth, screenHeight);

		EndDrawing();

		// Controls and updates
		flock.updateVel();
		flock.update(screenWidth, screenHeight);
	}

	return EXIT_SUCCESS;
}
