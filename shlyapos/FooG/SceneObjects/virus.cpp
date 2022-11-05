#include "virus.h"

Virus::Virus(const char *filename, const QColor& color, const Vector3f& center)
    : BaseModel(true, filename, color, center) { }
