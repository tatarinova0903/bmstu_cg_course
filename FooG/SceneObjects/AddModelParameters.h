#ifndef ADDMODELPARAMETERS_H
#define ADDMODELPARAMETERS_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>

#include "Material.h"
#include "basemodel.h"
#include "./constants.h"

struct AddModelParameters
{
    float moveX, moveY, moveZ;
    float scaleX, scaleY, scaleZ;

    QString filename;
    ModelType modelType;
    bool isVirus;

    Material material;

    float enX, enY, enZ;

    void configPerson()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleZ = 1.4;
        scaleY = -1.4;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/model.obj";
        modelType = PERSON;
        isVirus = false;
        material = Materials().skinMaterial;
    }

    void configLeftWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/left_wall.obj";
        modelType = WALL;
        isVirus = false;
        material = Materials().woodMaterial;
    }

    void configRightWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/right_wall.obj";
        modelType = WALL;
        isVirus = false;
        material = Materials().woodMaterial;
    }

    void configBackWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/back_wall.obj";
        modelType = WALL;
        isVirus = false;
        material = Materials().woodMaterial;
    }

    void configFloor()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/floor.obj";
        modelType = FLOOR;
        isVirus = false;
        material = Materials().woodMaterial;
    }

    void configVirus(float scale)
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = scale;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/sphere1.obj";
        modelType = VIRUS;
        isVirus = true;
        material = Materials().virusMaterial;
    }
};

#endif // ADDMODELPARAMETERS_H
