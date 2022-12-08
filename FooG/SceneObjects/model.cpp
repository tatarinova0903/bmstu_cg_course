#include "model.h"

Model::Model(const char *filename, const Material& material, ModelType modelType, const Vector3f& center)
    : BaseModel(false, filename, material, modelType, center) { }
