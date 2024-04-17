#ifndef __BOIDS__H__
#define __BOIDS__H__

#include <vector>

class Boid {
public:
	Boid();
	Boid(std::vector<float> pos, std::vector<float> dir, std::vector<float> acc, float mass=1.0, float range=1.0, float fov=1.57);
	Boid(std::vector<float> pos, std::vector<float> dir, float mass=1.0, float range=1.0, float fov=1.57);
	Boid(std::vector<float> pos, float mass=1.0, float range=1.0, float fov=1.57);
	~Boid()=default;


private:
	std::vector<float> pos;
	std::vector<float> vel;
	std::vector<float> acc;

	float mass;

	float range; //range of view
	float fov; //field of view
};

#endif
