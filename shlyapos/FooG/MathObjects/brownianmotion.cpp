#include <random>
#include "brownianmotion.h"

using namespace std;

BrownianMotion::BrownianMotion(float speed): speed(speed) { }

float BrownianMotion::get_random()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1);

    return dist6(rng) == 0 ? -0.01 : 0.01;
}

void BrownianMotion::calculate(std::vector<BaseModel *> &viruses)
{
#pragma omp for
    for (auto virus = viruses.begin(); virus < viruses.end(); virus++)
    {
        (*virus)->getCenter().x += get_random();
        (*virus)->getCenter().y += get_random();
        (*virus)->getCenter().z += get_random();
    }
}
