#include "Circle.hpp"


Circle::Circle(const Vector3f &_center, const float &_radius, Material *_m)
{
    this->center = _center;
    this->radius = _radius;
    this->radius_2 = _radius * _radius;
    this->area = M_PI * _radius * _radius;
    this->m = _m;
}
Intersection Circle::GetRayIntersection(const Ray &_ray)
{
    float x0,x1;
    // solveQuadratic()
}
BoundBox Circle::GetBoundBox()
{

}
float Circle::GetArea()
{
    return this->area;
}
void Circle::GetSample(Intersection &pos, float &pdf)
{

    pdf = 1 / area;
}
bool Circle::HasEmission() const
{
    return this->m->HasEmission();
}
