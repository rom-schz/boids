#include "flock.hpp"
#include "boid.hpp"
#include "raylib.h"


Flock::Flock() {
    boids = std::vector<Boid>();
}

void Flock::updateVel() {

    for (auto& boid : boids) {

        float vx=0; float vy=0;
        float vx_avg=0; float vy_avg=0;
        float x_avg=0; float y_avg=0;
        float close_dx=0; float close_dy=0;
        int neighbors = 0;

        for (auto& kin : boids) {
            
            // Do not match a boid with itself
            if (&kin == &boid) {
                break;
            }

            // If the kin is too close, move away
            if (boid.dist(kin) < shortRange) {
                close_dx += boid.getX() - kin.getX();
                close_dy += boid.getY() - kin.getY();
            }

            // If the kin is not too far away, get closer and update alignment
            else if (boid.dist(kin) < longRange) {
                x_avg += kin.getX();
                y_avg += kin.getY();

                vx_avg += kin.getVX();
                vy_avg += kin.getVY();
                neighbors++;
            }
        }

        if (neighbors > 0) {
            x_avg /= neighbors;
            y_avg /= neighbors;

            vx_avg /= neighbors;
            vy_avg /= neighbors;
        }

        vx += (x_avg - boid.getX()) * centeringFactor;
        vx += (vx_avg - boid.getVX()) * matchingFactor;
        vx += close_dx * avoidFactor;

        vy += (y_avg - boid.getY()) * centeringFactor;
        vy += (vy_avg - boid.getVY()) * matchingFactor;
        vy += close_dy * avoidFactor;

        boid.updateVel(vx, vy);
    }
}

void Flock::update(int screenWidth, int screenHeight) {
    for (auto& boid : boids) {
        boid.update(screenWidth, screenHeight);
    }
}

void Flock::addBoid(Boid boid) {
    boids.push_back(boid);
}

void Flock::render(int screenWidth, int screenHeight) {
    for (auto& boid : boids) {
        boid.render(screenWidth, screenHeight);
    }
}

void Flock::setCenteringFactor(float factor) {
    if (factor > 0) {
        centeringFactor = factor;
    }
}

void Flock::setAvoidFactor(float factor) {
    if (factor > 0) {
        avoidFactor = factor;
    }
}

void Flock::setMatchingFactor(float factor) {
    if (factor > 0) {
        matchingFactor = factor;
    }
}


