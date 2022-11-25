
#ifndef METEOR_PHYSICS_HPP
#define METEOR_PHYSICS_HPP

// #include "eigen-3.4.0/Eigen/Eigen"
// #include "eigen-3.4.0/Eigen/src/Core/Matrix.h"

#include "Eigen/Eigen"

#include "global.hpp"

using namespace Eigen;

namespace Physics
{

    // 数学工具
    namespace MathMethods
    {
        // return a^2
        inline float Pow2(float a)
        {
            return a * a;
        }

        // return a^5
        inline float Pow5(float a)
        {
            return a * a * a * a * a;
        }

        // return Positive eigenfunction
        inline int IsPositve(float a)
        {
            if (a > 0)
            {
                return 1;
            }
            return 0;
        }

        /**
         * @brief 将球面上的相对坐标转换为世界坐标系的坐标
         *
         * @param a 球面坐标
         * @param N 表面法线
         * @return Vector3f
         */
        inline Vector3f SphereToWorld(const Vector3f &a, const Vector3f &N)
        {
            Vector3f B, C;
            if (std::fabs(N.x()) > std::fabs(N.y()))
            {
                float invLen = 1.0f / std::sqrt(N.x() * N.x() + N.z() * N.z());
                C = Vector3f(N.z() * invLen, 0.0f, -N.x() * invLen);
            }
            else
            {
                float invLen = 1.0f / std::sqrt(N.y() * N.y() + N.z() * N.z());
                C = Vector3f(0.0f, N.z() * invLen, -N.y() * invLen);
            }
            B = C.cross(N);
            return a.x() * B + a.y() * C + a.z() * N;
        }
    }

    // 光学公式
    namespace Optics
    {
        /**
         * @brief 获取反射方向
         *
         * @param wi 光->交点
         * @param N 法线
         * @return Vector3f 交点->出射
         */
        inline Vector3f GetReflect(const Vector3f &wi, const Vector3f &N)
        {
            return wi - 2 * wi.dot(N) * N;
            // return (wi - 2 * wi.dot(N) * N).normalized();
        }

        /**
         * @brief 获取折射方向
         *
         * @param wi 光->交点
         * @param N 法线
         * @param eta_t 折射介质的绝对折射率（默认为1）
         * @param eta_i 入射介质的绝对折射率（默认为空气=1）
         * @return Vector3f 交点->出射
         */
        inline Vector3f GetRefract(const Vector3f &wi, const Vector3f &N, const float &eta_t, const float &eta_i = 1)
        {
            // I = I.normalized;
            // N = N.normalized;

            float etai_over_etat = eta_i / eta_t;

            float dt = wi.dot(N);

            float discriminant = 1.0f - etai_over_etat * etai_over_etat * (1 - dt * dt);

            if (discriminant > 0)
            {
                return etai_over_etat * (wi - N * dt) - sqrt(discriminant) * N;
            }
            else
            {
                return {0, 0, 0};
            }
        }

        inline float Snell(const Vector3f &wi, const Vector3f &N, const Vector3f &wt)
        {
            return 0;
        }

        /**
         * @brief 光线沿着wi方向，从介质m1射入m2中，得到该方向下，反射的反射系数（反射的能量小于入射时的能量）
         *
         * @param wi 入射方向
         * @param N 表面法线
         * @param eta_t 折射介质的绝对折射率
         * @param eta_i 入射介质的绝对折射率（默认为空气=1）
         * @return float 原光线的反射占比
         */
        inline float Fresnel(const Vector3f &wi, const Vector3f &N, const float &eta_t, const float &eta_i = 1)
        {

            //带i的是与入射相关的参数，带t的是与折射相关的参数
            // float eta_t = IOR;

            float costheta_i = -wi.dot(N);
            float sintheta_i = std::sqrt(1 - MathMethods::Pow2(costheta_i));

            float sintheta_t = eta_i * sintheta_i / eta_t;
            float costheta_t = std::sqrt(1 - MathMethods::Pow2(sintheta_t));

            float r_parallel, r_vertical;
            r_parallel = (eta_t * costheta_i - eta_i * costheta_t) / (eta_t * costheta_i + eta_i * costheta_t);
            r_vertical = (eta_i * costheta_i - eta_t * costheta_t) / (eta_i * costheta_i + eta_t * costheta_t);

            float F_r = 0.5f * (MathMethods::Pow2(r_parallel) + MathMethods::Pow2(r_vertical));

            return F_r;
        }

        /**
         * @brief 使用Schlick方法，近似Fresnel项
         * 我们需要预先计算表面在正视角(即以0度角正视表面)下的反应（𝐹0），然后就可以跟之前的Fresnel-Schlick算法一样，根据观察角度来进行插值
         * @param wi 入射光方向
         * @param n 表面法线
         * @param eta_t 折射介质的绝对折射率
         * @param eta_i 入射介质的绝对折射率（默认为空气=1）
         * @return float 原光线的反射占比
         */
        inline Vector3f FresnelSchlick(const Vector3f &wi, const Vector3f &N, const float &eta_t, const float &eta_i = 1)
        {

            float eta = eta_i / eta_t; // 此处的eta1/eta称之为：相对IOR

            if (std::abs(eta - 1) < EPSILON) // disney 2015年的发表，相对IOR接近1时，近似效果不好，建议使用原来的Fresnel方程
            {
                float nom = Fresnel(wi, N, eta_t);
                return Vector3f(nom, nom, nom);
            }

            float costheta = -wi.dot(N); //入射角

            // 当介质2大于介质1（空气）的折射率时，cos(theta)=cos(折射角)
            if (eta_t > eta_i)
            {
                // 使用了snell折射定律，eta1*sin(theta_1)=eta2*sin(theta_2)

                float cos_2_t = 1 - MathMethods::Pow2(eta_i) * (1 - MathMethods::Pow2(costheta)) / MathMethods::Pow2(eta_t);
                costheta = std::sqrt(cos_2_t); // 需要使用折射角
            }

            // 一般F0Dielectrics可以设为0.04 (反射率4%)，UE4 [12]和Frostbite [25]也是这么用的。
            // 现实中有些材质的反射率更低，比如水是2%，而有些绝缘材质则反射率更高，例如钻石是0.18 [35]。
            // 渲染器中这个数值一般都是写死的，不随材质而改变，这个数值对最后的结果也有很大的影响。

            Vector3f F0;

            int f0_flag = 0;

            if (f0_flag == 0)
            {
                F0 = {0.04f, 0.04f, 0.04f};
            }
            else
            {
                float temp = ((eta_t - eta_i) / (eta_t + eta_i)) * ((eta_t - eta_i) / (eta_t + eta_i));
                F0 = {temp, temp, temp};
            }

            Vector3f rslt = F0 + (Vector3f(1.f, 1.f, 1.f) - F0) * MathMethods::Pow5(1 - costheta);

            return rslt;
        }
    }
}
#endif