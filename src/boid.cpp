#include "boid.hpp"
#include "raylib.h"

#include <math.h>
#include <iostream>

Boid::Boid(float x, float y, float vx, float vy) {
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}

void Boid::update(int screenWidth, int screenHeight) {
	// Update velocity
	vx += nextVX;
	vy += nextVY;

	// Re-normalize the velocity if necessary
	float norm = std::sqrt(vx * vx + vy * vy);
	if (norm < minSpeed) {
		vx = (vx / norm) * minSpeed;
		vy = (vy / norm) * minSpeed;
	} else if (norm > maxSpeed) {
		vx = (vx / norm) * maxSpeed;
		vy = (vy / norm) * maxSpeed;
	}

	// Update position
	x += vx;
	if (x > screenWidth / 2) {
		x = -screenWidth / 2;
	} else if (x < - screenWidth / 2) {
		x = screenWidth / 2;
	}

	y += vy;
	if (y > screenHeight / 2) {
		y = -screenHeight / 2;
	} else if (y < - screenHeight / 2) {
		y = screenHeight / 2;
	}
}

void Boid::updateVel(float vx, float vy) {
	nextVX = vx;
	nextVY = vy;
}

void Boid::render(int screenWidth, int screenHeight) {
	float norm = std::sqrt(vx * vx + vy * vy);

	int factor = 4;

	float dx = factor * vx / norm;
	float dy = factor * vy / norm;

	float ox = -dy;
	float oy = dx;

	float X = x + screenWidth/2;
	float Y = y + screenHeight/2;

	Vector2 A = (Vector2) {X + 5 * dx, Y + 5 * dy};
	Vector2 B = (Vector2) {X - 3 * dx + 2 * ox, Y - 3 * dy + 2 * oy};
	Vector2 C = (Vector2) {X - 3 * dx - 2 * ox, Y - 3 * dy - 2 * oy};

	DrawTriangle(B, A, C, RED);
}

float Boid::getX() {
	return x;
}

float Boid::getY() {
	return y;
}

float Boid::getVX() {
	return vx;
}

float Boid::getVY() {
	return vy;
}

float Boid::getMaxSpeed() {
	return maxSpeed;
}

float Boid::getMinSpeed() {
	return minSpeed;
}

float Boid::dist(Boid boid) {
	float X2 = (x - boid.getX()) * (x - boid.getX());
	float Y2 = (y - boid.getY()) * (y - boid.getY());

	return std::sqrt(X2 + Y2);
}

