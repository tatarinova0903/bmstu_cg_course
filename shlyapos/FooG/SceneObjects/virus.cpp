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

void Virus::renewColor()
{
    std::chrono::system_clock::time_point curTimePoint = std::chrono::system_clock::now();
    unsigned long cur = std::chrono::duration_cast<std::chrono::seconds>(curTimePoint.time_since_epoch()).count();
    unsigned long lifeTime = cur - bornTime;
    QColor surfaceColor = settledMaterial.color;
    if (settledMaterial.value == AIR)
    {
        setColor(calculateNewColor(surfaceColor, lifeTime, AIR_TIME));
    }
    if (settledMaterial.value == SKIN)
    {
        setColor(calculateNewColor(surfaceColor, lifeTime, SKIN_TIME));
    }
    if (settledMaterial.value == WOOD)
    {
        setColor(calculateNewColor(surfaceColor, lifeTime, WOOD_TIME));
    }
    if (settledMaterial.value == PAPER)
    {
        setColor(calculateNewColor(surfaceColor, lifeTime, PAPER_TIME));
    }
    if (settledMaterial.value == CERAMICS)
    {
        setColor(calculateNewColor(surfaceColor, lifeTime, CERAMICS_TIME));
    }
}

void Virus::renewDate()
{
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
    bornTime = std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch()).count();
}

QColor Virus::calculateNewColor(QColor surfaceColor, unsigned long lifeTime, unsigned long maxLifeTime)
{
    QColor virusColor = Materials().virusMaterial.color;
    int virusRed, virusGreen, virusBlue, surfaceRed, surfaceGreen, surfaceBlue;
    surfaceColor.getRgb(&surfaceRed, &surfaceGreen, &surfaceBlue);
    virusColor.getRgb(&virusRed, &virusGreen, &virusBlue);
    int redDiff = surfaceRed - virusRed;
    int greenDiff = surfaceGreen - virusGreen;
    int blueDiff = surfaceBlue - virusBlue;
    float newRed = virusRed + lifeTime * redDiff / maxLifeTime;
    float newGreen = virusGreen + lifeTime * greenDiff / maxLifeTime;
    float newBlue = virusBlue + lifeTime * blueDiff / maxLifeTime;
    if (newRed > surfaceRed || newGreen > surfaceGreen || newBlue > surfaceBlue)
    {
        return surfaceColor;
    }
    return QColor(newRed, newGreen, newBlue);
}

