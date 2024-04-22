#ifndef __FLOCK__H__
#define __FLOCK__H__

#include "boid.hpp"

#include <vector>

class Flock {
public:
    Flock();

    void update(int screenWidth, int screenHeight);
    void updateVel();
    void addBoid(Boid boid);

    void render(int screenWidth, int screenHeight);

    void setCenteringFactor(float factor);
    void setAvoidFactor(float factor);
    void setMatchingFactor(float factor);

private:
    std::vector<Boid> boids;
    float shortRange=10;
    float longRange=50;

    float centeringFactor=0.0005;
    float avoidFactor=0.05;
    float matchingFactor=0.05;

};

#endif