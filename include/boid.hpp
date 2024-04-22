#ifndef __BOID__H__
#define __BOID__H__

#include <vector>

class Boid {
public:
	Boid(float x, float y, float vx, float vy);
	~Boid()=default;

	void update();

private:
	float x; float y;
	float vx; float vy;

	float maxSpeed;
	float minSpeed;

	float avoidFactor;
	float centeringFactor;
	float matchingFactor;

	void separation();
	void alignment();
	void cohesion();
};

#endif
