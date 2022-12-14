#pragma once

#include "Eigen/Eigen"
using namespace Eigen;

class Camera
{

public:
    //约定俗成：相机位于(0,0,0)，头上是y轴正方向，看向z轴负方向

    Vector3f pos;    //相机坐标
    Vector2f rotate; //相机旋转角度

    float fov;         //视野 https://blog.csdn.net/SnoopyNa2Co3/article/details/83893093
    float aspectRatio; //屏幕宽高比，相当于分辨率
    float zNear;

    Camera()
    {
        pos = {0, 0, 0};
        rotate = {0, 0};
        fov = 90;
        aspectRatio = 4 / 3.f;
        zNear = 1;
    }

    Camera(float &_x, float &_y, float &_z)
    {

        pos = {_x, _y, _z};
    };

    Camera(const Vector3f _pos, const float _fov, const Vector2f _rotate = Vector2f(0.f, 0.f))
    {
        pos = _pos;
        fov = _fov;
        rotate = _rotate;
    }

    void SetCamera(const Vector3f _pos, const float _fov)
    {
        pos = _pos;
        // rotate = _rotate;
        fov = _fov;
    };
};
