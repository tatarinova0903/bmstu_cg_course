#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <vector>
#include "vector3.h"

class BrownianMotion
{
public:
    BrownianMotion();

    void calculate(std::vector<Vector3f *> &virus_centers);
};

#endif // BROWNIANMOTION_H
