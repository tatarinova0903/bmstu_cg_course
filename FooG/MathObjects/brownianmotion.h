#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <vector>
#include "vector3.h"
#include "./SceneObjects/basemodel.h"

#define SIZE 2048
#define POWER 11

class BrownianMotion
{
private:
    std::vector<std::vector<Vector3f>> data;
    int virusCount;

    size_t i = 0;

    // Алгоритмы
    void classic(std::vector<Vector3f *> &virus_centers);
    void midpoint(std::vector<Vector3f *> &virus_centers);

    // Вспомогательные функции
    float get_random();
    float getNormalRandom();

public:
    BrownianMotion();

    void calculate(std::vector<Vector3f *> &virus_centers);
    void setVirusCountAndResetAllIfNeeded(int);
};

#endif // BROWNIANMOTION_H
