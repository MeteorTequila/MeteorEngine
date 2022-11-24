#ifndef METEOR_CIRCLE_H
#define METEOR_CIRCLE_H

#include "Object.hpp"

class Circle : public Object
{
public:
    Vector3f center;
    float radius;
    float radius_2;
    Material *m;
    float area;

    Circle(const Vector3f &_center, const float &_radius, Material *_m);
    Intersection GetRayIntersection(const Ray &_ray);
    BoundBox GetBoundBox();
    float GetArea();
    void GetSample(Intersection &pos, float &pdf);
    bool HasEmission() const;
};
#endif
