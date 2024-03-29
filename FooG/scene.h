#ifndef SCENE_H
#define SCENE_H

#include "./SceneObjects/basemodel.h"
#include "./SceneObjects/camera.h"
#include "./SceneObjects/lightsourcepoint.h"
#include "SceneObjects/virus.h"
#include "SceneObjects/model.h"
#include "MathObjects/brownianmotion.h"

class Scene
{
private:
    BrownianMotion brownianMotion;
    Camera mainCamera;
    std::vector<BaseModel> models;
    std::vector<LightSourcePoint> lightSources;
    float virus_speed;

    Vector3f getSceneCenter();
    bool checkSettled(Virus *virus, bool needChangeColor);
    bool isVirusNearModel(Model *, Virus *);

public:
    Scene();
    ~Scene();

    // Models
    int    countModels();
    void   addModel(const BaseModel&, const Vector3f& scale = Vector3f(1, 1, 1));
    BaseModel& getModel(const int&);
    void   editModel(Vector3f&, Vector3f&, Vector3f&, Material&, Material&);
    void clearModels();

    // Lights
    void              addLightSource(const Vector3f&, const float&);
    LightSourcePoint& getLightSource(const int&);
    int               getLightSourceCount();
    void              editLight(const int&, const Vector3f&, const float&);

    // Camera
    Camera&   getCamera();
    void      setCamera(const Vector3f&, const Vector3f&, const Vector3f&);

    Vector3f& getCameraPos();
    Vector3f& getCameraView();
    Vector3f& getCameraUp();

    void      upDownCamera(const float&);
    void      rotateCamera(const float&);
    void      strafeCamera(const float&);
    void      movingCamera(const float&);

    // Virus
    bool hasVirus();
    void reCalculateVirus(int virusCount, bool needChangeColor);
    void setVirusSpeed(float speed);
};

#endif // SCENE_H
