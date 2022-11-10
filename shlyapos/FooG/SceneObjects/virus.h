#ifndef VIRUS_H
#define VIRUS_H

#include <chrono>
#include "basemodel.h"
#include "Material.h"

class Virus: public BaseModel
{
private:
    std::chrono::system_clock::time_point start;
    MaterialType materialType = AIR;

public:
    Virus(const char*, const Vector3f& center = Vector3f(0, 0, 0));

    void setSettled(BaseModel *place);
};

#endif // VIRUS_H
