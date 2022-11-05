#ifndef VIRUS_H
#define VIRUS_H

#include "basemodel.h"

class Virus: public BaseModel
{
public:
    Virus(const char*, const QColor&, const Vector3f& center = Vector3f(0, 0, 0));
};

#endif // VIRUS_H
