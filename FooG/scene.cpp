#include "scene.h"
#include "MathObjects/brownianmotion.h"
#include "SceneObjects/model.h"
#include "constants.h"
#include <QDebug>
#include <iterator>
#include <vector>

// Constructors
Scene::Scene()
    : mainCamera(Camera()), models(std::vector<BaseModel>()), lightSources(std::vector<LightSourcePoint>())
{
    brownianMotion = BrownianMotion();
}

Scene::~Scene()
{

}

Vector3f Scene::getSceneCenter()
{
    float x = 0.0, y = 0.0, z = 0.0;
    if (countModels() == 0)
    {
        return Vector3f(x, y, z);
    }
    for (auto it = models.begin(); it < models.end(); it++) {
        if (it->modelType == WALL)
        {
            y = it->getCenter().y;
        }
        if (it->modelType == FLOOR)
        {
            z = it->getCenter().z;
            x = it->getCenter().x;
        }
     }
    return Vector3f(x, y, z);
}

// Models
int Scene::countModels()
{
    return models.size();
}

void Scene::addModel(const BaseModel& newModel, const Vector3f& scale)
{
    models.push_back(newModel);
    models.back().scale(scale, getSceneCenter());
}

BaseModel& Scene::getModel(const int& idx)
{
    return models[idx];
}

void Scene::editModel(Vector3f& center, Vector3f& scale, Vector3f& rotate, Material& wallMaterial, Material& floorMaterial)
{
    for (auto it = models.begin(); it < models.end(); it++)
    {
        it->setCenter(center);
        it->scale(scale, getSceneCenter());
        it->rotate(rotate);
        if (!it->isVirus)
        {
            if (it->modelType == WALL)
            {
                it->setMaterial(wallMaterial);
            }
            if (it->modelType == FLOOR)
            {
                it->setMaterial(floorMaterial);
            }
        }
     }
}

void Scene::clearModels()
{
    models.clear();
}


// Lights
void Scene::addLightSource(const Vector3f& lPos, const float& lPower)
{
    lightSources.push_back(LightSourcePoint(lPos, lPower));
}

LightSourcePoint& Scene::getLightSource(const int& idx)
{
    return lightSources[idx];
}

int Scene::getLightSourceCount()
{
    return lightSources.size();
}

void Scene::editLight(const int& idx, const Vector3f& pos, const float& power)
{
    lightSources[idx].setPosition(pos);
    lightSources[idx].setIntensity(power);
}



// Camera methods
Camera& Scene::getCamera()
{
    return mainCamera;
}

void Scene::setCamera(const Vector3f& pos, const Vector3f& view, const Vector3f& up)
{
    mainCamera = Camera(pos, view, up);
}

Vector3f& Scene::getCameraPos()
{
    return mainCamera.getPosition();
}

Vector3f& Scene::getCameraView()
{
    return mainCamera.getView();
}

Vector3f& Scene::getCameraUp()
{
    return mainCamera.getUp();
}

void Scene::upDownCamera(const float& speed)
{
    Vector3f pos = mainCamera.getPosition();

    if (fabs(pos.y + speed) < 1.25)
        mainCamera.upDown(speed);
}

void Scene::rotateCamera(const float& speed)
{
    mainCamera.rotateView(speed);
}

void Scene::strafeCamera(const float& speed)
{
    mainCamera.update();
    mainCamera.strafe(speed);
}

void Scene::movingCamera(const float& speed)
{
    mainCamera.move(speed);
}

// Virus
void Scene::reCalculateVirus(int virusCount, bool needChangeColor)
{
    std::vector<Vector3f *> virus_centers;
#pragma omp for
    for (auto model = models.begin(); model < models.end(); model++)
    {
        if (model->isVirus && model->getIsVisible())
        {
            if (!checkSettled((Virus *)&*model, needChangeColor))
            {
                virus_centers.push_back(&(model->getCenter()));
            }
            ((Virus *)&*model)->renewAlpha();
        }
    }
    brownianMotion.setVirusCountAndResetAllIfNeeded(virusCount);
    brownianMotion.calculate(virus_centers);
}

void Scene::setVirusSpeed(float speed) // TODO: - NEED IT ???
{
    virus_speed = speed;
}

bool Scene::hasVirus()
{
    for (auto model = models.begin(); model < models.end(); model++)
    {
        if (model->isVirus)
        {
            return true;
        }
    }
    return false;
}

bool Scene::checkSettled(Virus *virus, bool needChangeColor)
{
    if (virus->getIsSettled())
    {
        return true;
    }
    for (auto model = models.begin(); model < models.end(); model++)
    {
        if (!model->isVirus)
        {
            // проверяем осел ли вирус на данной модели?
            if (isVirusNearModel((Model *)&*model, (Virus *)virus))
            {
//                std::cout << virus->getGeometricCenter().x << " " << virus->getGeometricCenter().y << " "
//                          << virus->getGeometricCenter().z<< std::endl;
                virus->setSettled(&*model);
                if (needChangeColor)
                {
                    virus->setColor(QColor(0,255, 0));
                }
                return true;
            }
        }
    }
    return false;
}

bool Scene::isVirusNearModel(Model *model, Virus *virus)
{
    double distance = model->minDistanceTo(virus->getGeometricCenter());
//    if (distance < VIRUS_RADIUS * virus->getScaleK())
//    {
//        std::cout << distance << std::endl;
//    }
    return distance < VIRUS_RADIUS * virus->getScaleK();
}
