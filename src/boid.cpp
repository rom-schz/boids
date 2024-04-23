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
	if (x > screenWidth) {
		x = 0;
	} else if (x < 0) {
		x = screenWidth;
	}

	y += vy;
	if (y > screenHeight) {
		y = 0;
	} else if (y < 0) {
		y = screenHeight;
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

	Vector2 A = (Vector2) {x + 5 * dx, y + 5 * dy};
	Vector2 B = (Vector2) {x - 3 * dx + 2 * ox, y - 3 * dy + 2 * oy};
	Vector2 C = (Vector2) {x - 3 * dx - 2 * ox, y - 3 * dy - 2 * oy};

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

