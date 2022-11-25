#ifndef METEOR_RAY_H
#define METEOR_RAY_H

// #include "eigen-3.4.0/Eigen/Eigen"

#include "Eigen/Eigen"
using namespace Eigen;

class Ray //: public Object
{
public:
    Vector3f origin;
    Vector3f direction;
    Vector3f energy;
    double t = 0;

    Ray(const Vector3f &_origin, const Vector3f &_direction);
    Ray(const Vector3f &_origin, const Vector3f &_direction,const Vector3f &_energy);
    Vector3f PosAfterT(float &_t) const;
};



#endif