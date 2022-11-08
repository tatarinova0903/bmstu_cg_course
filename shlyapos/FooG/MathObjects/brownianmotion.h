#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <vector>
#include "vector3.h"
#include "./SceneObjects/basemodel.h"

class BrownianMotion
{
private:
    float speed;

    float get_random();

public:
    BrownianMotion(float speed);

    void calculate(std::vector<BaseModel *> &viruses);
};

#endif // BROWNIANMOTION_H
