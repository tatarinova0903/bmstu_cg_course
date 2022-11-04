#include <random>
#include "brownianmotion.h"

using namespace std;

BrownianMotion::BrownianMotion() { }

float get_random()
{
    static default_random_engine e;
    static uniform_real_distribution<> dis(-0.05, 0.05);
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
