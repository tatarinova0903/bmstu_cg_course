#include <chrono>
#include "virus.h"
#include "./constants.h"

Virus::Virus(const char *filename, const Vector3f& center)
    : BaseModel(true, filename, Materials().virusMaterial, VIRUS, center) {
    renewDate();
}

void Virus::setSettled(BaseModel *place)
{
    isSettled = true;
    settledMaterial = place->getMaterial();
    renewDate();
}

bool Virus::getIsSettled()
{
    return isSettled;
}

void Virus::renewAlpha()
{
    std::chrono::system_clock::time_point curTimePoint = std::chrono::system_clock::now();
    unsigned long cur = std::chrono::duration_cast<std::chrono::seconds>(curTimePoint.time_since_epoch()).count();
    unsigned long lifeTime = cur - bornTime;
    if (settledMaterial.value == AIR)
    {
        alpha = 1.0 - lifeTime / AIR_TIME;
    }
    if (settledMaterial.value == SKIN)
    {
        alpha = 1.0 - lifeTime / SKIN_TIME;
    }
    if (settledMaterial.value == WOOD)
    {
        alpha = 1.0 - lifeTime / WOOD_TIME;
    }
    if (settledMaterial.value == PAPER)
    {
        alpha = 1.0 - lifeTime / PAPER_TIME;
    }
    if (settledMaterial.value == CERAMICS)
    {
        alpha = 1.0 - lifeTime / CERAMICS_TIME;
    }
}

void Virus::renewDate()
{
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
    bornTime = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch()).count();
}

