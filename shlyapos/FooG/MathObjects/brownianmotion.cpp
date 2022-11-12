#include <random>
#include <math.h>
#include "brownianmotion.h"

using namespace std;

BrownianMotion::BrownianMotion() { }

float BrownianMotion::getNormalRandom()
{
    static default_random_engine e;
    static uniform_real_distribution<> dis(-0.1, 0.1);
    return dis(e);
}

float BrownianMotion::get_random()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1);

    return dist6(rng) == 0 ? -0.01 : 0.01;
}

void BrownianMotion::calculate(std::vector<Vector3f *> &virus_centers)
{
    midpoint(virus_centers);
}

void BrownianMotion::classic(std::vector<Vector3f *> &virus_centers)
{
#pragma omp for
    for (auto center = virus_centers.begin(); center < virus_centers.end(); center++)
    {
        (*center)->x += get_random();
        (*center)->y += get_random();
        (*center)->z += get_random();
    }
}

void BrownianMotion::midpoint(std::vector<Vector3f *> &virus_centers)
{
    size_t virus_count = virus_centers.size();
    for (size_t k = 0; k < virus_count; k++)
    {
        virus_centers.at(k)->x += data.at(k).at(i).x;
        virus_centers.at(k)->y += data.at(k).at(i).y;
        virus_centers.at(k)->z += data.at(k).at(i).z;
    }
    i++;
    if (i > SIZE + 1)
    {
        i = 1;
    }
}

void BrownianMotion::setVirusCountAndResetAllIfNeeded(int newVirusCount)
{
    if (virusCount == newVirusCount)
    {
        return;
    }
    virusCount = newVirusCount;
    float sigma = 0.2;
    data = std::vector<std::vector<Vector3f>>(virusCount, std::vector<Vector3f>(SIZE + 1));
    for (int k = 0; k < virusCount; k++)
    {
        data.at(k).at(0) = Vector3f(0.0, 0.0, 0.0);
        data.at(k).at(SIZE) = Vector3f(sigma * getNormalRandom(), sigma * getNormalRandom(), sigma * getNormalRandom());
        for (int j = 1; j <= POWER; j++)
        {
            for (int i = 1; i <= pow(2, (j - 1)); i++)
            {
                int ind = (2 * i - 1) * pow(2, POWER - j);
                int old1 = (i - 1) * pow(2, POWER - j + 1);
                int old2 = i * pow(2, POWER -j + 1);
                data.at(k).at(ind).x = (data.at(k).at(old1).x + data.at(k).at(old2).x) / 2 + sigma * getNormalRandom() / pow(2, (j + 1) / 2);
                data.at(k).at(ind).y = (data.at(k).at(old1).y + data.at(k).at(old2).y) / 2 + sigma * getNormalRandom() / pow(2, (j + 1) / 2);
                data.at(k).at(ind).z = (data.at(k).at(old1).z + data.at(k).at(old2).z) / 2 + sigma * getNormalRandom() / pow(2, (j + 1) / 2);
            }
        }
    }
//    for (int i = 0; i < SIZE + 1; i++)
//    {
//        std::cout << arr.at(i).x << " ";
//    }
}

