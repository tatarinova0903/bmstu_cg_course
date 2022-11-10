#include "virus.h"

Virus::Virus(const char *filename, const Vector3f& center)
    : BaseModel(true, filename, Materials().virusMaterial, VIRUS, center) {
    start = std::chrono::system_clock::now();
}

void Virus::setSettled(BaseModel *place)
{
//    materialType = place;
}
