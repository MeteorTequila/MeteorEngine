#include "Ray.hpp"

// 以源点和方向定义一道射线
Ray::Ray(const Vector3f &_origin, const Vector3f &_direction) : origin(_origin), direction(_direction)
{
    // origin = _origin;
    // direction = _direction;
}
Ray::Ray(const Vector3f &_origin, const Vector3f &_direction, const Vector3f &_energy)
{
    origin = _origin;
    direction = _direction;
    energy = _energy;
}
// 返回t时刻光线的位置
Vector3f Ray::PosAfterT(float &temp_t) const
{
    return origin + direction * temp_t;
}
