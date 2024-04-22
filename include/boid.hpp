#ifndef __BOID__H__
#define __BOID__H__

#include <vector>

class Boid {
public:
	Boid(float x, float y, float vx, float vy);
	~Boid()=default;

	void update(int screenWidth, int screenHeight);

	void updateVel(float vx, float vy);

	void render(int screenWidth, int screenHeight);

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

	float maxSpeed=5;
	float minSpeed=10;

};

#endif
