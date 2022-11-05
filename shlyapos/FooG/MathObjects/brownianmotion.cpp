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

void BrownianMotion::calculate(std::vector<Vector3f *> &virus_centers)
{
    for (auto center = virus_centers.begin(); center < virus_centers.end(); center++)
    {
        (*center)->x += get_random();
        (*center)->y += get_random();
        (*center)->z += get_random();
    }
}
