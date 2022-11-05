#ifndef MODEL_H
#define MODEL_H

#include "basemodel.h"

class Model: public BaseModel
{
public:
    Model(const char*, const QColor&, ModelType modelType, const Vector3f& center = Vector3f(0, 0, 0));
};

#endif // MODEL_H
