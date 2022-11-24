#ifndef METEOR_SPHERE_H
#define METEOR_SPHERE_H

#include "Object.hpp"

class Sphere : public Object
{
public:
    Vector3f center;       //球体中心点
    float radius, radius2; //半径，半径的平方
    float area;            //面积
    Material *m;           //材质

    Sphere(const Vector3f &_center, const float &_radius, Material *_m);

    Intersection GetRayIntersection(const Ray &_ray);
    BoundBox GetBoundBox();
    float GetArea();
    void GetSample(Intersection &pos, float &pdf);
    bool HasEmission() const;
};

#endif