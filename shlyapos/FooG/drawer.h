#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include <QGraphicsScene>

#include <cmath>
#include <string>

#include "zbuffer.h"
#include "scene.h"

#define FAULT 500

// Very thicc boi...
class Drawer : public QGraphicsScene
{
    Q_OBJECT

private:
    int w, h;

    // Scene
    Scene scene;

    QColor bgColor = QColor(50, 50, 50);

    // Screen
    QImage canvas;

    void initCanvas();
    void clearCanvas();
    void updateCanvas();

    // Z-Buffer
    ZBuffer zBuffer;

    void initZBuffer();
    void clearZBuffer();

    // Color cache
    std::vector<std::vector<QColor>> colorCache;

    void initColorCache();
    void clearColorCache();

    // Screen
    void updateScreen();
    void clearScreen();

    // Draw processing
    void  objectProcessing(BaseModel&, Vector3f&, Vector3f&, Vector3f&);
    float lightProcessing(const Vector3f&, const Vector3f&);
    void  triangleProcessing(Vector3i&, Vector3i&, Vector3i&,
                            const QColor&, float&, float&, float&);

    int  wPerm, hPerm;
    bool checkIsVisible(const Vector3i&);

public:
    explicit Drawer(const int&, const int&, QObject *parent = nullptr);
    ~Drawer();

    void draw();

    // Model
    void addModel(Vector3f&, Vector3f&, QString&, QColor&, ModelType);
    void editModel(Vector3f&, Vector3f&, Vector3f&, QColor&, QColor&);

    // Light
    void addLight(const Vector3f&, const float&);
    void editLight(const int&, const Vector3f&, const float& power = 500);

    // Camera
    void upDownCamera(const float&);
    void rotateCamera(const float&);
    void strafeCamera(const float&);
    void movingCamera(const float&);

    // Virus
    bool hasVirus();
    void addVirus(Vector3f& center, Vector3f& scale, QString& filename, QColor& color, int count);
    void reCalculateVirus();
    void setVirusSpeed(float speed);
};

inline QRgb iColor(const QRgb& a, const float& i);

#endif // DRAWER_H
