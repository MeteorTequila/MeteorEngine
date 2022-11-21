#ifndef METEOR_SHADER_H
#define METEOR_SHADER_H

#include "eigen-3.4.0/Eigen/Eigen"
#include "global.hpp"

using namespace Eigen;

namespace Shader
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

    // 法线分布函数
    namespace NormalDistributionShader
    {

        // Phong 法线分布函数
        inline float ND_Phong(const float &alpha, const float &NdotH)
        {
            return std::pow(alpha, alpha) * (alpha + 2) / M_PI / 2;
        }

        // Phong 法线分布函数（UE4方法）
        inline float ND_Phong_UE4(const float &alpha, const float &NdotH)
        {
            // UE4使用alpha_phong=2*alpha_UE^(-2)-2
            float alpha_2 = alpha * alpha;
            float alpha_p = 2 / alpha_2 - 2;
            return std::pow(NdotH, alpha_p) / M_PI / alpha_2;
        }

        // Beckmann 法线分布函数
        inline float ND_Beckmann(const float &alpha, const float &NdotH)
        {
            // alpha_phong = 2 * alpha_beckmann^(-2) - 2，alpha_beckmann介于[0.025,0.2]
            float alpha_2 = alpha * alpha;
            float NdotH_2 = NdotH * NdotH;
            float e_pow = (NdotH_2 - 1) / alpha_2 / NdotH_2;
            return std::exp(e_pow) / M_PI / alpha_2 / NdotH_2 / NdotH_2;
        }

        // GGX法线分布函数，即Trowbridge-Reitz分布
        inline float ND_GGX(const float &alpha, const float &NdotH)
        {
            float roughness_2 = alpha * alpha;
            float NdotH_2 = NdotH * NdotH;
            float pow2_base = NdotH_2 * (roughness_2 - 1) + 1;
            return roughness_2 / M_PI / pow2_base / pow2_base;
        }

        // GTR法线分布函数，即Generalized-Trowbridge-Reitz
        inline float ND_GTR(const float &alpha, const float &NdotH, const int gamma)
        {
            // gamma控制高光尾部效果
            // gamma=1时，GTR即Berry分布
            // gamma=2时，GTR即GGX（Trowbridge-Reitz）分布
            float roughness_2 = alpha * alpha;
            float NdotH_2 = NdotH * NdotH;
            float pow_base = NdotH_2 * (roughness_2 - 1) + 1;
            return roughness_2 / M_PI / std::pow(pow_base, gamma);
        }

    }

    // 几何分布函数
    namespace GeometryShader
    {

    }
}

#endif