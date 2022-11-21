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
        // https://zhuanlan.zhihu.com/p/69380665

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

    // 阴影遮挡函数
    namespace GeometryShader
    {
        // https://zhuanlan.zhihu.com/p/81708753
        // BSDF定义了一个几何函数 G 用以模拟微表面由于相互遮挡而导致光线的能量丢失的现象，这个函数就叫做阴影遮挡函数，
        // 从定义不难看出，这个函数的取值应该也是从[0,1]的。同时，几何函数有两种形式：
        // G1——微平面在单个方向（光照方向l或视线方向v）上可见比例，光照对应遮蔽函数 masking function；视线对应阴影函数 shadowing function.
        // G2——微平面在光照和视线方向共同可见的比例，称为联合遮蔽阴影函数 joint masking-shadowing function.
        // 其中，G2由G1推导而来，同时一般微表面材质计算所说的几何函数就是指G2

        // Smith遮蔽函数
        inline float G_Smith(const float &NdotV)
        {
            if (NdotV > 0)
            {
                return 1;
            }
            return 0;
        }

        // Smith遮蔽函数，Disney方法
        inline float G_Smith_Disney(const float &NdotV, const float &NdotL, const float &alpha)
        {
            float alpha_GGX = (0.5 + alpha / 2.f) * (0.5 + alpha / 2.f); //粗糙度重映射
            float alpha_GGX_2 = alpha_GGX * alpha_GGX;
            float frac_below_1 = NdotV + std::sqrt(alpha_GGX_2 + (1 - alpha_GGX_2) * NdotV * NdotV);
            float frac_below_2 = NdotL + std::sqrt(alpha_GGX_2 + (1 - alpha_GGX_2) * NdotL * NdotL);

            float g_1 = 2.f * NdotV / frac_below_1; // 观察方向
            float g_2 = 2.f * NdotL / frac_below_2; // 光源方向
            return g_1 * g_2;
        }

        // Smith遮蔽函数，UE4方法。采用GGX-Smith Correlated Joint 近似方案
        // [Heitz 2014, "Understanding the Masking-Shadowing Function in Microfacet-Based BRDFs"]
        inline float G_Smith_UE4(const float &NdotV, const float &NdotL, const float &alpha)
        {
            float roughness_2 = alpha * alpha;
            float lambda_v = NdotL * (NdotV * (1 - roughness_2) + roughness_2);
            float lambda_l = NdotV * (NdotL * (1 - roughness_2) + roughness_2);
            return 0.5 / (lambda_v + lambda_l);
        }

        // Smith遮蔽函数，Unity DRP方法。采用GGX-Smith Correlated Joint近似方案
        // [Heitz 2014, "Understanding the Masking-Shadowing Function in Microfacet-Based BRDFs"]
        inline float G_Smith_Unity(const float &NdotV, const float &NdotL, const float &alpha)
        {
            float roughness_2 = alpha * alpha;
            float lambda_v = NdotL * (NdotV * (1 - alpha) + alpha); // NdotV * (1 - alpha) + alpha 是一个近似值
            float sqrt_base = (-NdotL * roughness_2 + NdotL) * NdotL + roughness_2;
            float lambda_l = NdotV * std::sqrt(sqrt_base);
            return 0.5 / (lambda_v + lambda_l);
        }

        // Smith遮蔽函数，Google Filament渲染器方法。采用GGX-Smith Joint近似方案
        inline float G_Smith_Google(const float &NdotV, const float &NdotL, const float &alpha)
        {
            float roughness_2 = alpha * alpha;
            float sqrt_base_l = (-NdotL * roughness_2 + NdotL) * NdotL + roughness_2;
            float lambda_l = NdotV * std::sqrt(sqrt_base_l);
            float sqrt_base_v = (-NdotV * roughness_2 + NdotV) * NdotV + roughness_2;
            float lambda_v = NdotL * std::sqrt(sqrt_base_v);
            return 0.5 / (lambda_v + lambda_l);
        }

        // Smith遮蔽函数，Respawn Entertainment方法。采用GGX-Smith Joint近似方案
        // [2017]Respawn Entertainment的 GGX-Smith Joint近似方案
        inline float G_Smith_Respawn(const float &NdotV, const float &NdotL, const float &alpha)
        {
            float roughness_2 = alpha * alpha;
            float sqrt_base_l = (-NdotL * roughness_2 + NdotL) * NdotL + roughness_2;
            float lambda_l = NdotV * std::sqrt(sqrt_base_l);
            float sqrt_base_v = (-NdotV * roughness_2 + NdotV) * NdotV + roughness_2;
            float lambda_v = NdotL * std::sqrt(sqrt_base_v);
            return 0.5 / (lambda_v + lambda_l);
        }

    }
}

#endif