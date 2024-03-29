#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>
#include <chrono>

#define MAX_SPEED 1000
#define MIN_SPEED 100

int frames = 0;
auto frameTime = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Курсовая работа");
    this->setWindowIcon(QIcon("icon_speedrun.png"));

    ui->centralwidget->setStyleSheet("QWidget {background: rgba(50, 50, 50, 255);}");

    initDrawer();
    initLables();
    initButton();
    initFields();
    initComboBoxes();
    initTimer();

    this->resize(1000, 800);

    modelCnt  = 0;
    lightCnt  = 0;

    lightPos.push_back(Vector3f(100, 1000, 100));
    drawer->addLight(Vector3f(100, 1000, 100), 1300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTimer()
{
    timer = new QTimer(this);
}

void MainWindow::initDrawer()
{
    size_t w = ui->graphicsView->width();
    size_t h = ui->graphicsView->height();

    drawer = new Drawer(w, h, this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignCenter);

    ui->graphicsView->setScene(drawer);
}

void MainWindow::initButton()
{
    connect(ui->pushButton_loadScene, SIGNAL(released()), this, SLOT(addModels()));
    connect(ui->pushButton_clear, SIGNAL(released()), this, SLOT(clear()));

    connect(ui->pushButton_start, SIGNAL(released()), this, SLOT(startVirusSpread()));
    connect(ui->pushButton_stop, SIGNAL(released()), this, SLOT(stopVirusSpread()));

    connect(ui->pushButton_mapply, SIGNAL(released()), this, SLOT(applyModelChange()));
    connect(ui->pushButton_mcancel, SIGNAL(released()), this, SLOT(cancelLineEditsModel()));

    connect(ui->pushButton_lapply, SIGNAL(released()), this, SLOT(applyLightChange()));
    connect(ui->pushButton_lcancel, SIGNAL(released()), this, SLOT(cancelLineEditsLight()));
}

void MainWindow::initLables()
{
    // Models
    ui->lbl_model_move->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mmove_x->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mmove_y->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mmove_z->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");

    ui->lbl_model_scale->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mscale_x->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");

    ui->lbl_mrotate->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mrotate_x->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mrotate_y->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_mrotate_z->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");

    // Lights
    ui->lbl_lights->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_lmove->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_lmove_x->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_lmove_y->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
    ui->lbl_lmove_z->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");

    ui->lbl_power->setStyleSheet("QLabel {color: rgba(200, 200, 200, 255);}");
}

void MainWindow::initFields()
{
    ui->le_mmove_x->setText("0.0");
    ui->le_mmove_y->setText("0.0");
    ui->le_mmove_z->setText("0.0");

    ui->le_mscale_x->setText("1");

    ui->le_mrotate_x->setText("0");
    ui->le_mrotate_y->setText("0");
    ui->le_mrotate_z->setText("0");

    ui->virus_count_field->setText("20");

    ui->speed_slider->setValue(50);

    ui->le_lmove_x->setText("100.0");
    ui->le_lmove_y->setText("500.0");
    ui->le_lmove_z->setText("100.0");
    ui->le_power->setText("200");
}

void MainWindow::initComboBoxes()
{
    for (size_t i = 0; i < wallMaterials.size(); i++)
    {
        ui->walls_comboBox->addItem(QString::fromStdString(wallMaterials[i].raw_value));
    }
    for (size_t i = 0; i < floorMaterials.size(); i++)
    {
        ui->floor_comboBox->addItem(QString::fromStdString(floorMaterials[i].raw_value));
    }
}

// Virus animation
void MainWindow::startVirusSpread()
{
    int speed = MAX_SPEED - (MAX_SPEED - MIN_SPEED) * ui->speed_slider->value() / 100.0;
    timer->setInterval(speed);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveVirus);

    if (!drawer->hasVirus())
    {
        AddModelParameters virus = AddModelParameters();
        float kScale = ui->le_mscale_x->text().toFloat();
        virus.configVirus(kScale);
        setAddModelParams(virus);
    }

    timer->start();
}

void MainWindow::stopVirusSpread()
{
    timer->stop();
}

void MainWindow::moveVirus()
{
    bool needChangeColor = ui->changeColorCheckBox->isChecked();
//    std::chrono::time_point<std::chrono::system_clock> start, end;
//    start = std::chrono::system_clock::now();
    drawer->reCalculateVirus(ui->virus_count_field->text().toInt(), needChangeColor);
    drawer->draw();
//    end = std::chrono::system_clock::now();
//    std::cout << (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()) << std::endl;
}

// Model
void MainWindow::applyModelChange()
{
    if (centersM.size() == 0)
        return;

    Vector3f center, scale, rotate;

    // For move
    if (ui->le_mmove_x->text().isEmpty() ||
        ui->le_mmove_y->text().isEmpty() ||
        ui->le_mmove_z->text().isEmpty())
    {
        center = Vector3f(0, 0, 0);
    }
    else
    {
        center = Vector3f(ui->le_mmove_x->text().toFloat(),
                          ui->le_mmove_y->text().toFloat(),
                          ui->le_mmove_z->text().toFloat());
    }

    // For scale
    if (ui->le_mscale_x->text().isEmpty())
    {
        scale = Vector3f(1, 1, 1);
    }
    else
    {
        float kScale = ui->le_mscale_x->text().toFloat();
        scale = Vector3f(kScale, kScale, kScale);
    }

    // For rotate
    if (ui->le_mrotate_x->text().isEmpty() ||
        ui->le_mrotate_y->text().isEmpty() ||
        ui->le_mrotate_z->text().isEmpty())
    {
        rotate = Vector3f(0, 0, 0);
    }
    else
    {
        rotate = Vector3f(ui->le_mrotate_x->text().toFloat(),
                          ui->le_mrotate_y->text().toFloat(),
                          ui->le_mrotate_z->text().toFloat());
    }

    // For colors
    Material wallMaterial = wallMaterials.at(ui->walls_comboBox->currentIndex());
    Material floorMaterial = floorMaterials.at(ui->floor_comboBox->currentIndex());

    drawer->editModel(center, scale, rotate, wallMaterial, floorMaterial);
    drawer->draw();
}

void MainWindow::cancelLineEditsModel()
{
    ui->le_mmove_x->setText("0.0");
    ui->le_mmove_y->setText("0.0");
    ui->le_mmove_z->setText("0.0");

    ui->le_mscale_x->setText("1");

    ui->le_mrotate_x->setText("0");
    ui->le_mrotate_y->setText("0");
    ui->le_mrotate_z->setText("0");
}

// Light
void MainWindow::changeLight()
{
    Vector3f currentCenter = lightPos[0];

    ui->le_lmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_lmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_lmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_power->setText("500");
}

void MainWindow::applyLightChange()
{
    if (lightPos.size() == 0)
        return;

    int idx = 0;
    Vector3f pos;

    if (ui->le_lmove_x->text().isEmpty() ||
        ui->le_lmove_y->text().isEmpty() ||
        ui->le_lmove_z->text().isEmpty())
    {
        pos = lightPos[idx];
    }
    else
    {
        pos = Vector3f(ui->le_lmove_x->text().toFloat(),
                       ui->le_lmove_y->text().toFloat(),
                       ui->le_lmove_z->text().toFloat());
    }

    if (ui->le_power->text().isEmpty())
        drawer->editLight(idx, pos);
    else
        drawer->editLight(idx, pos, ui->le_power->text().toFloat());

    drawer->draw();
}

void MainWindow::cancelLineEditsLight()
{
    int idx = 0;
    Vector3f currentCenter = lightPos[idx];

    ui->le_lmove_x->setText(std::to_string(currentCenter.x).c_str());
    ui->le_lmove_y->setText(std::to_string(currentCenter.y).c_str());
    ui->le_lmove_z->setText(std::to_string(currentCenter.z).c_str());

    ui->le_power->setText("200");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    switch (key)
    {
    case Qt::Key_Equal:
        drawer->movingCamera(1);
        break;
    case Qt::Key_Minus:
        drawer->movingCamera(-1);
        break;
    case Qt::Key_A:
        drawer->strafeCamera(-0.5);
        break;
    case Qt::Key_D:
        drawer->strafeCamera(0.5);
        break;

    case Qt::Key_I:
        drawer->upDownCamera(0.25);
        break;
    case Qt::Key_J:
        drawer->rotateCamera(-0.05);
        break;
    case Qt::Key_K:
        drawer->upDownCamera(-0.25);
        break;
    case Qt::Key_L:
        drawer->rotateCamera(0.05);
        break;
    }

    drawer->draw();
}



// Add new model
void MainWindow::addModels()
{
    AddModelParameters person = AddModelParameters();
    person.configPerson();
    setAddModelParams(person);

    AddModelParameters leftWall = AddModelParameters();
    leftWall.configLeftWall();
    setAddModelParams(leftWall);

    AddModelParameters rightWall = AddModelParameters();
    rightWall.configRightWall();
    setAddModelParams(rightWall);

    AddModelParameters backWall = AddModelParameters();
    backWall.configBackWall();
    setAddModelParams(backWall);

    AddModelParameters floor = AddModelParameters();
    floor.configFloor();
    setAddModelParams(floor);
}

void MainWindow::setAddModelParams(AddModelParameters& newParams)
{
    Vector3f center(newParams.moveX, newParams.moveY, newParams.moveZ);
    Vector3f scaleK(newParams.scaleX, newParams.scaleY, newParams.scaleZ);

    if (newParams.isVirus)
    {
        int virus_count = ui->virus_count_field->text().toInt();
        drawer->addVirus(center, scaleK, newParams.filename, virus_count);
    }
    else
    {
        drawer->addModel(center, scaleK, newParams.filename, newParams.material, newParams.modelType);
    }

    centersM.push_back(center);

    modelCnt++;

    frames = 0;
    frameTime = 0;
    drawer->draw();
}

// Clear
void MainWindow::clear()
{
    timer->stop();
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveVirus);
    drawer->clearScene();
    drawer->draw();
}

