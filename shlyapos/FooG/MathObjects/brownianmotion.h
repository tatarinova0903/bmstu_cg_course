#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <vector>
#include "vector3.h"

class BrownianMotion
{
private:
    float speed;

    float get_random();

public:
    BrownianMotion(float speed);

    void calculate(std::vector<Vector3f *> &virus_centers);
};

#endif // BROWNIANMOTION_H
