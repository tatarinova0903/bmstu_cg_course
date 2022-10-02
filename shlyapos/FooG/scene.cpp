#include "scene.h"

#include <QDebug>
#include <iterator>
#include <vector>

// Constructors
Scene::Scene()
    : mainCamera(Camera()), models(std::vector<Model>()), lightSources(std::vector<LightSourcePoint>())
{

}



// Models
int Scene::countModels()
{
    return models.size();
}

void Scene::addModel(const Model& newModel, const Vector3f& scale)
{
    models.push_back(newModel);
    models.back().scale(scale);
}

Model& Scene::getModel(const int& idx)
{
    return models[idx];
}

void Scene::editModel(Vector3f& center, Vector3f& scale, Vector3f& rotate)
{
    for (auto it = models.begin(); it < models.end(); it++) {
        it->setCenter(center);
        it->scale(scale);
        it->rotate(rotate);
     }
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
Camera&   Scene::getCamera()
{
    return mainCamera;
}

void      Scene::setCamera(const Vector3f& pos, const Vector3f& view, const Vector3f& up)
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



void    Scene::upDownCamera(const float& speed)
{
    Vector3f pos = mainCamera.getPosition();

    if (fabs(pos.y + speed) < 1.25)
        mainCamera.upDown(speed);
}

void    Scene::rotateCamera(const float& speed)
{
    mainCamera.rotateView(speed);
}

void    Scene::strafeCamera(const float& speed)
{
    mainCamera.update();
    mainCamera.strafe(speed);
}

void    Scene::movingCamera(const float& speed)
{
    mainCamera.move(speed);
}
