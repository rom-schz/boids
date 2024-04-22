#include "boid.hpp"

#include <math.h>

Boid::Boid(float x, float y, float vx, float vy) {
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}

void Boid::update() {
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
	y += vy;
}

void Boid::updateVel(float vx, float vy) {
	nextVX = vx;
	nextVY = vy;
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