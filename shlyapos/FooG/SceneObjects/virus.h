#ifndef VIRUS_H
#define VIRUS_H

#include "basemodel.h"
#include "Material.h"

class Virus: public BaseModel
{
private:
    void renewDate();

    QColor calculateNewColor(QColor, unsigned long, unsigned long);

public:
    Virus(const char*, const Vector3f& center = Vector3f(0, 0, 0));

    void setSettled(BaseModel *place);
    bool getIsSettled();

    void renewAlpha();
};

#endif // VIRUS_H
