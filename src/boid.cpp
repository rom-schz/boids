#include "boid.hpp"

Boid::Boid(float x, float y, float vx, float vy) {
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}


void Boid::update() {
	this->separation();
	this->alignment();
	this->cohesion();
}

void Boid::separation() {
	
}