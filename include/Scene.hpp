#pragma once

#include "eigen-3.4.0/Eigen/Eigen"

// #include "Eigen/Eigen"

#include "Object.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Acceleration.hpp"

using namespace Eigen;

class Scene
{
public:
    int width = 1366;             //宽
    int height = 768;             //高
    Vector3f bgcolor = {0, 0, 0}; //背景色

    std::vector<Object *> objects; //场景中的对象指针数组
    Acceleration *acc;             //加速结构
    Camera eye;                    //主视角

    Scene();

    Scene(int w, int h);

    void add(Object *object);

    void PreProcessing();

    Intersection GetIntersection(const Ray &ray) const;

    Vector3f CastRay(const Ray &ray) const;

    Vector3f CastRay_2(const Ray &ray) const;

private:
    void GetEmissionSample(Intersection &pos, float &pdf) const;
};