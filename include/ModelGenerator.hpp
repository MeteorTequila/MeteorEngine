#pragma once
#include "Object.hpp"

class Sphere
{
public:
    Vector3f center;
    float radius;

    Sphere (const Vector3f &p, const float &r) : center(p), radius(r){};
};

