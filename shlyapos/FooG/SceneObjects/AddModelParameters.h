#ifndef ADDMODELPARAMETERS_H
#define ADDMODELPARAMETERS_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>

struct AddModelParameters
{
    float moveX, moveY, moveZ;
    float scaleX, scaleY, scaleZ;

    QString filename;
    QString modelName;
    bool isVirus;

    QColor color;

    float enX, enY, enZ;

    void configPerson()
    {
        moveX = moveZ = 0.0;
        moveY = 0.3;
        scaleX = scaleZ = 1.4;
        scaleY = -1.4;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/person.obj";
        modelName = "person";
        isVirus = false;
        color = QColor(240, 161, 137);
    }

    void configLeftWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/left_wall.obj";
        modelName = "leftWall";
        isVirus = false;
        color = QColor(255, 255, 255);
    }

    void configRightWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/right_wall.obj";
        modelName = "rightWall";
        isVirus = false;
        color = QColor(255, 255, 255);
    }

    void configBackWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/back_wall.obj";
        modelName = "backWall";
        isVirus = false;
        color = QColor(255, 255, 255);
    }

    void configFloor()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/floor.obj";
        modelName = "floor";
        isVirus = false;
        color = QColor(255, 255, 255);
    }

    void configVirus()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 0.04;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/sphere.obj";
        modelName = "virus";
        isVirus = true;
        color = QColor(255, 0, 0, 127);
    }
};

#endif // ADDMODELPARAMETERS_H
