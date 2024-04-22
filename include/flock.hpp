#ifndef __FLOCK__H__
#define __FLOCK__H__

#include "boid.hpp"

#include <vector>

class Flock {
public:
    Flock();

    void update();
    void addBoid(Boid boid);

private:
    std::vector<Boid> boids;
    float shortRange=10;
    float longRange=;

    float centeringFactor;
    float avoidFactor;
    float matchingFactor;

};

#endif