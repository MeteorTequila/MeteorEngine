#ifndef METEOR_SHADER_H
#define METEOR_SHADER_H

#include "eigen-3.4.0/Eigen/Eigen"
#include "global.hpp"

using namespace Eigen;

namespace MaterialShader
{
    namespace MaterialPdf
    {
        inline float uniformlyPdf = 0.5f / M_PI;                       // 对于表面粗糙度均匀的物体来说，所有方向反射的概率一致，均为pi/2
        inline float specularPdf = 1;                                  // 对于纯镜面表面来说，反射方向的光源只会来自于一个方向
        inline float importancePdf = get_random_float() * 0.5f / M_PI; // 重要性采样，对于表main粗糙不一的物体来说，出射的光源来自于不同入射光源在不同入射概率下的影响
    }

    namespace MaterialColor
    {

    }
}

#endif