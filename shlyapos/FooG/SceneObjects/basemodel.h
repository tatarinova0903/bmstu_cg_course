#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <QColor>

#include "../MathObjects/vector3.h"
#include "../MathObjects/vector3.hpp"
#include "Material.h"
#include "../MathObjects/transformmatrix.h"

enum ModelType
{
    PERSON, WALL, FLOOR, VIRUS
};

class BaseModel
{
protected:
    Vector3f center;
    Vector3f geometricCenter;
    float scaleK;
    std::vector<Vector3f> verts;

    // attention, this Vector3i means vertex/uv/normal
    std::vector<std::vector<Vector3i>> faces;
    std::vector<Vector3f> norms;

    Material material;

    bool isSettled = false;

    unsigned long bornTime;
    Material settledMaterial = Materials().airMaterial;

    Vector3f normalCalculate(const Vector3f&, const Vector3f&, const Vector3f&);
    void normalsProcessing();

public:
    BaseModel(bool isVirus, const char*, const Material&, ModelType modelType, const Vector3f& center = Vector3f(0, 0, 0));

    bool isVirus;
    ModelType modelType;

    // Distance
    double minDistanceTo(Vector3f);

    // Center
    Vector3f& getCenter();
    Vector3f getGeometricCenter();
    void      setCenter(const Vector3f&);

    // Vertes
    int       getVertsCount();
    Vector3f& vert(const int&);

    // Faces
    int              getFacesCount();
    std::vector<int> face(const int&);

    // Normals
    int       getNormsCount();
    void      setNorm(const int&, const int&, const Vector3f&);
    Vector3f& norm(const int&, const int&);

    // Color
    QColor& getColor();
    void    setColor(const QColor&);

    // Material
    void    setMaterial(const Material&);
    Material& getMaterial();

    void scale(const Vector3f&, const Vector3f&);
    void rotate(const Vector3f&);

    float getScaleK();
};

#endif // BASEMODEL_H
