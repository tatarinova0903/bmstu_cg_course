#include <random>
#include "brownianmotion.h"

using namespace std;

BrownianMotion::BrownianMotion(float speed): speed(speed) { }

float BrownianMotion::get_random()
{
    static default_random_engine e;
    float max_value = speed / 1000;
    static uniform_real_distribution<> dis(-max_value, max_value);
    return dis(e);
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
