#ifndef __BOID__H__
#define __BOID__H__

#include <vector>

class Boid {
public:
	Boid(float x, float y, float vx, float vy);
	~Boid()=default;

	void update();

	void updateVel(float vx, float vy);

	float getX();
	float getY();

	float getVX();
	float getVY();

	float getMaxSpeed();
	float getMinSpeed();

	float dist(Boid boid);


private:
	float x; float y;
	float vx; float vy;
	float nextVX; float nextVY;

	float maxSpeed;
	float minSpeed;

	float avoidFactor;
	float centeringFactor;
	float matchingFactor;

};

#endif
