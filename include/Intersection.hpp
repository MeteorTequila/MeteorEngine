#ifndef METEOR_INTERSECTION_H
#define METEOR_INTERSECTION_H

#include "Material.hpp"
#include "Eigen/Eigen"

class Object;

class Intersection
{

public:
    bool IsHappend;  //是否相交
    Vector3f coords; //交点坐标
    Vector3f wi;     //入射方向
    Vector3f wo;     //出射方向
    Vector3f normal; //交点法线
    float distance;  //相交时间
    Object *object;  //交点物体
    Material *m;     //交点材质
    Vector3f emission;

    Intersection()
    {
        IsHappend = false;
        distance = std::numeric_limits<float>::max();
        coords = Vector3f(0.f, 0.f, 0.f);
        normal = Vector3f(0.f, 0.f, 0.f);
        wi = Vector3f(0.f, 0.f, 0.f);
        wo = Vector3f(0.f, 0.f, 0.f);
        m = nullptr;
        object = nullptr;
        Vector3f emission = Vector3f(0.f, 0.f, 0.f);
    }
};

#endif