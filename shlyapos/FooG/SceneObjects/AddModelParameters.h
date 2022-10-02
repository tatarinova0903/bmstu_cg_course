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

    QColor color;

    float enX, enY, enZ;

    void configPerson()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleZ = 1.0;
        scaleY = -1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/person.obj";
        modelName = "person";
        color = QColor(255, 255, 255, 127);
    }

    void configLeftWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/left_wall.obj";
        modelName = "leftWall";
        color = QColor(255, 255, 255, 127);
    }

    void configRightWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/right_wall.obj";
        modelName = "rightWall";
        color = QColor(255, 255, 255, 127);
    }

    void configBackWall()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/back_wall.obj";
        modelName = "backWall";
        color = QColor(255, 255, 255, 127);
    }

    void configFloor()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleY = scaleZ = 1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/floor.obj";
        modelName = "floor";
        color = QColor(255, 255, 255, 127);
    }
};

#endif // ADDMODELPARAMETERS_H
