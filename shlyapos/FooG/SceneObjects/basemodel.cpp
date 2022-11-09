#include <math.h>
#include "basemodel.h"
#include "./constants.h"

BaseModel::BaseModel(bool isVirus, const char *filename, const QColor& color, ModelType modelType, const Vector3f& center)
    : center(center), color(color), isVirus(isVirus), modelType(modelType)
{
    std::ifstream in;

    in.open(filename, std::ifstream::in);

    if (in.fail())
        return;

    std::string line;

    while (!in.eof())
    {
        std::getline(in, line);

        std::istringstream iss(line.c_str());
        char trash;

        if (!line.compare(0, 2, "v "))
        {
            iss >> trash;
            Vector3f v;

            for (int i = 0; i < 3; i++)
                iss >> v[i];

            verts.push_back(v);
        }

        else if (!line.compare(0, 3, "vn "))
        {
            iss >> trash >> trash;
            Vector3f n;

            for (int i = 0; i < 3; i++)
                iss >> n[i];

            norms.push_back(n);
        }

        else if (!line.compare(0, 2, "f "))
        {
            std::vector<Vector3i> f;
            Vector3i tmp;

            iss >> trash;

            while (iss >> tmp[0] >> trash >> tmp[1] >> trash >> tmp[2])
            {
                for (int i = 0; i < 3; i++)
                    tmp[i]--;

                f.push_back(tmp);
            }
            faces.push_back(f);
        }
    }
    // For time tests
    //std::cerr << "Verteces - " << verts.size() << std::endl;
}

// Distance
double BaseModel::minDistanceTo(Vector3f point)
{
    float minDistance = DOUBLE_MAX;
    for (auto face = faces.begin(); face < faces.end(); face++)
    {
        Vector3f p1 = verts.at(face->at(0).x);
        Vector3f p2 = verts.at(face->at(1).x);
        Vector3f p3 = verts.at(face->at(2).x);

        if (modelType != PERSON)
        {
            // 1. Найдем нормальный вектор плоскости
            Vector3f n = Vector3f(p1, p2)^Vector3f(p1, p3);

            // 2. Находим проекцию точки на плоскость
            float t = (n.x * p1.x - n.x * point.x + n.y * p1.y - n.y * point.y + n.z * p1.z - n.z * point.z) / (n.x * n.x + n.y * n.y + n.z * n.z);
            Vector3f projection = Vector3f(point.x + t * n.x, point.y + t * n.y, point.z + t * n.z);

            // 3. Если проекция находится внутри основания тетраедра, то minDist = dist(projection, point)
            float s = 0.5 * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
            float s1 = 0.5 * fabs((projection.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (projection.y - p3.y));
            float s2 = 0.5 * fabs((p1.x - p3.x) * (projection.y - p3.y) - (projection.x - p3.x) * (p1.y - p3.y));
            float s3 = 0.5 * fabs((p1.x - projection.x) * (p2.y - projection.y) - (p2.x - projection.x) * (p1.y - projection.y));

            if (fabs(s - (s1 + s2 + s3)) < EPS)
            {
               float dist = point.distance(projection);
               if (dist < minDistance)
               {
                   minDistance = dist;
               }
               continue;
            }
        }

        // 4. Иначе minDist = min( dist(point, p1), dist(point, p2), dist(point, p3) )
        float dist1 = point.distance(p1);
        float dist2 = point.distance(p2);
        float dist3 = point.distance(p3);
        float dist = std::min({dist1, dist2, dist3});
        if (dist < minDistance)
        {
            minDistance = dist;
        }
    }
    return minDistance;
}

// Center
Vector3f& BaseModel::getCenter()
{
    return center;
}

void BaseModel::setCenter(const Vector3f& newCenter)
{
    center.x += newCenter.x;
    center.y += newCenter.y;
    center.z += newCenter.z;
}



// Vertes
int BaseModel::getVertsCount()
{
    return verts.size();
}

Vector3f& BaseModel::vert(const int& idx)
{
    return verts[idx];
}



// Faces
int BaseModel::getFacesCount()
{
    return faces.size();
}

std::vector<int> BaseModel::face(const int& idx)
{
    std::vector<int> face;
    size_t size = faces[idx].size();

    for (size_t i = 0; i < size; i++)
        face.push_back(faces[idx][i][0]);

    return face;
}



// Normals
int BaseModel::getNormsCount()
{
    return norms.size();
}

void BaseModel::setNorm(const int& iface, const int& nvert, const Vector3f& n)
{
    int idx = faces[iface][nvert][2];
    norms[idx] = n;
}

Vector3f& BaseModel::norm(const int& iface, const int& nvert)
{
    int idx = faces[iface][nvert][2];
    return norms[idx].normalize();
}

Vector3f BaseModel::normalCalculate(const Vector3f& a, const Vector3f& b, const Vector3f& c)
{
    Vector3f n = (c - a) ^ (b - a);
    return n;
}

void BaseModel::normalsProcessing()
{
    size_t nface = faces.size();

    for (size_t i = 0; i < nface; i++)
    {
        std::vector<int> f = face(i);

        setNorm(i, 0, normalCalculate(vert(f[0]), vert(f[1]), vert(f[2])));
        setNorm(i, 1, normalCalculate(vert(f[1]), vert(f[2]), vert(f[0])));
        setNorm(i, 2, normalCalculate(vert(f[2]), vert(f[0]), vert(f[1])));
    }
}



// Color
QColor& BaseModel::getColor()
{
    return color;
}

void BaseModel::setColor(const QColor& newColor)
{
    color = newColor;
}



void BaseModel::scale(const Vector3f& k, const Vector3f& sceneCenter)
{
    scaleK = k.x;

    int nverts = verts.size();

    for (int i = 0; i < nverts; i++)
    {
        verts[i].x = sceneCenter.x + (verts[i].x - sceneCenter.x) * k.x;
        verts[i].y = sceneCenter.y + (verts[i].y - sceneCenter.y) * k.y;
        verts[i].z = sceneCenter.z + (verts[i].z - sceneCenter.z) * k.z;
    }

    normalsProcessing();
}


void BaseModel::rotate(const Vector3f& angle)
{
    std::shared_ptr<Matrix> m1(new MoveMatrix(center.x, center.y, center.z));
    std::shared_ptr<Matrix> m2(new MoveMatrix(-center.x, -center.y, -center.z));

    std::shared_ptr<Matrix> rx(new RotateOxMatrix(angle.x * M_PI / 180));
    std::shared_ptr<Matrix> ry(new RotateOyMatrix(angle.y * M_PI / 180));
    std::shared_ptr<Matrix> rz(new RotateOzMatrix(angle.z * M_PI / 180));

    size_t nverts = verts.size();

    for (size_t i = 0; i < nverts; i++)
    {
        verts[i].transform(m2);

        verts[i].transform(rx);
        verts[i].transform(ry);
        verts[i].transform(rz);

        verts[i].transform(m1);
    }
}

float BaseModel::getScaleK()
{
    return scaleK;
}
