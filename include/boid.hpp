#ifndef __BOID__H__
#define __BOID__H__

#include <vector>

class Boid {
public:
	Boid(float x, float y, float vx, float vy);
	~Boid()=default;

	void update();

	void updateCohesion(float x_avg, float y_avg);
	void updateAlignment(float vx_avg, float vy_avg);
	void updateSeparation(float close_dx, float close_dy);

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
