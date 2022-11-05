#include "model.h"

Model::Model(const char *filename, const QColor& color, ModelType modelType, const Vector3f& center)
    : BaseModel(false, filename, color, modelType, center) { }
