#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QKeyEvent>

#include <string>
#include <chrono>
#include <vector>

#include "MathObjects/vector3.h"
#include "SceneObjects/AddModelParameters.h"
#include "drawer.h"
#include "SceneObjects/Material.h"

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

    std::vector<Material> materials = Materials().value;

    int modelCnt, lightCnt;

    std::vector<Vector3f> centersM;
    std::vector<Vector3f> centersS;
    std::vector<Vector3f> lightPos;

    void initDrawer();
    void initLables();
    void initButton();
    void initFields();
    void initComboBoxes();

    void keyPressEvent(QKeyEvent *event);

private slots:

    // Model
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

    // Virus
    void startVirusSpread();
    void stopVirusSpread();
    void moveVirus();
};
#endif // MAINWINDOW_H
