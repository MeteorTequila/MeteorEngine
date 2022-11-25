#pragma once
#ifndef METEOR_OBJECT_H
#define METEOR_OBJECT_H


#include "Eigen/Eigen"

#include "Ray.hpp"
#include "Intersection.hpp"
#include "Material.hpp"
#include "BoundBox.hpp"
#include "global.hpp"

using namespace Eigen;

class Object
{
public:
    // bool hasEmit = false;
    Material *m = nullptr;
    Object(){};
    virtual ~Object() {}
    virtual Intersection GetRayIntersection(const Ray &_ray) = 0;
    virtual BoundBox GetBoundBox() = 0;
    virtual float GetArea() = 0;
    virtual void GetSample(Intersection &pos, float &pdf) = 0;
    virtual bool HasEmission() const = 0;
};

#endif
