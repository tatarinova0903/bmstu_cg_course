#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QKeyEvent>

#include <string>
#include <chrono>

#include "MathObjects/vector3.h"
#include "SceneObjects/AddModelParameters.h"
#include "drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Drawer *drawer;

    int modelCnt, lightCnt;

    std::vector<Vector3f> centersM;
    std::vector<Vector3f> centersS;
    std::vector<Vector3f> lightPos;

    void initDrawer();
    void initLables();
    void initButton();

    void keyPressEvent(QKeyEvent *event);

private slots:

    // Model
    void setDafaultParametrs();
    void applyModelChange();
    void cancelLineEditsModel();

    // Light
    void changeLight();
    void applyLightChange();
    void cancelLineEditsLight();

    // Window
    void clear();
    void addModels();
    void setAddModelParams(AddModelParameters&);
};
#endif // MAINWINDOW_H
