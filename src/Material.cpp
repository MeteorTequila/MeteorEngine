#include "Material.hpp"
#include "Intersection.hpp"
#include "Physics.hpp"
#include "eigen-3.4.0/Eigen/src/Core/Matrix.h"
#include "global.hpp"
#include <cmath>

Material::Material()
{
    this->emission = {0, 0, 0};
    this->IOR = 1.2f;
    this->reflectivity = 0.8;
    this->transmissivity = 0;
    this->kd = {0.2f, 0.4f, 0.8f};
    this->ks = {1 - 0.2f, 1 - 0.8f, 1 - 0.8f};
    this->exp = 10;
};

// TODO 材质初始化方法
Material::Material(MaterialType _mt)
{
    this->mt = _mt;

    switch (_mt)
    {
    case DIFFUSAL:
        this->emission = {0, 0, 0};
        this->IOR = 1.51f; //硅酸盐折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.725f, 0.71f, 0.68f};
        this->ks = {1.f - this->kd.x(), 1.f - this->kd.y(), 1.f - this->kd.z()};
        this->exp = 10;

        break;

    case MIRROR:
        this->emission = {0, 0, 0};
        this->IOR = 1.33f; //银的折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = {1.f - this->kd.x(), 1.f - this->kd.y(), 1.f - this->kd.z()};
        this->exp = 10;

        break;

    case TRANSPARENT:
        this->emission = {0, 0, 0};
        this->IOR = 1.544f; //水晶的折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = {1.f - this->kd.x(), 1.f - this->kd.y(), 1.f - this->kd.z()};
        this->exp = 10;

    case IRREGULAR:
        this->emission = {0, 0, 0};
        this->IOR = 1.2f;
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = {1 - 0.2f, 1 - 0.8f, 1 - 0.8f};
        this->exp = 10;

        break;

    default:
        this->emission = {0, 0, 0};
        this->IOR = 1.2f;
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = {1 - 0.2f, 1 - 0.8f, 1 - 0.8f};
        this->exp = 10;
        break;
    }
};

// 判断当前材质是否能够发光
bool Material::HasEmission() const
{
    if (emission.x() > EPSILON || emission.y() > EPSILON || emission.z() > EPSILON)
    {
        return true;
    }
    return false;
}

// 获取当前材质的发光参数
Vector3f Material::GetEmission() const
{

    return this->emission;
}

/**
 * @brief 对以当前交点为圆心的单位半球均匀采样，得到一个随机的反射方向
 *
 * @param wi 入射方向
 * @param N 表面法线
 * @return Vector3f 随机的出射方向
 */
Vector3f Material::GetRandomReflect(const Vector3f &wi, const Vector3f &N)
{
    // 不同的随机办法
    int sample_flag = 1;

    if (sample_flag == 0)
    { // games101 作业7的的采样方法
        float x_1 = get_random_float(), x_2 = get_random_float();
        float z = std::fabs(1.0f - 2.0f * x_1);
        float r = std::sqrt(1.0f - z * z), phi = 2 * M_PI * x_2;
        Vector3f localRay(r * std::cos(phi), r * std::sin(phi), z);
        return Physics::MathMethods::SphereToWorld(localRay, N).normalized();
    }

    if (sample_flag == 1)
    {
        //随机[0,1]取值
        float r_1 = get_random_float(), r_2 = get_random_float();

        //随机设置球坐标系的theta和phi
        float phi = 0.5 * M_PI * r_1;
        float theta = 2 * M_PI * r_2;
        float r = 1.f;

        //得到球面坐标
        Vector3f sphereCoord(r * cos(phi) * cos(theta), r * cos(phi) * sin(theta), r * sin(phi));

        //转换成世界坐标
        return Physics::MathMethods::SphereToWorld(sphereCoord, N).normalized();
    }
}

/**
 * @brief 法线分布项
 * https://zhuanlan.zhihu.com/p/69380665
 * @param N 表面法线
 * @param h 光源方向与人眼方向的半程向量
 * @return float
 */
float Material::DistributionOfNormal(const Vector3f &N, const Vector3f &h)
{
    int flag_normal = 2; //默认设置为2，主流使用GGX

    float n_dot_h_2 = N.dot(h) * N.dot(h);

    // Blinn-Phong分布(UE4方法)
    if (flag_normal == 0)
    {
        // Blinn-Phong
        // return std::pow((N.dot(h)), alpha_phong) * (alpha_phong + 2) / M_PI / 2;

        // UE4使用alpha_phong=2*alpha_UE^(-2)-2
        float alpha_2 = alpha_phong * alpha_phong;
        float alpha_p = 2 / alpha_2 - 2;
        return std::pow((N.dot(h)), alpha_p) / M_PI / alpha_2;
    }

    // Beckmann分布
    if (flag_normal == 1)
    {
        // alpha_phong=2*alpha_beckmann^(-2)-2，alpha_beckmann介于[0.025,0.2]
        float alpha_2 = alpha_phong * alpha_phong;
        float e_pow = (n_dot_h_2 - 1) / alpha_2 / n_dot_h_2;
        return std::exp(e_pow) / M_PI / alpha_2 / n_dot_h_2 / n_dot_h_2;
    }

    // GGX分布，即Trowbridge-Reitz分布
    if (flag_normal == 2)
    {
        float roughness_2 = roughness * roughness;
        return roughness_2 / M_PI / Physics::MathMethods::Pow2(n_dot_h_2 * (roughness_2 - 1) + 1);
    }
    // GTR分布，即Generalized-Trowbridge-Reitz
    if (flag_normal == 3)
    {
        // 控制高光尾部效果。gamma=1时，GTR即Berry分布，gamma=2时，GTR即GGX（Trowbridge-Reitz）分布
        float gamma = 2;
        float roughness_2 = roughness * roughness;
        float pow_base = n_dot_h_2 * (roughness_2 - 1) + 1;
        return roughness_2 / M_PI / std::pow(pow_base, gamma);
    }

    return 0;
}


/**
 * @brief 几何函数
 * https://zhuanlan.zhihu.com/p/81708753
 * 几何函数（Geometry Function）是一个0到1之间的标量，描述了微平面自阴影的属性，
 * 表示了具有半矢量法线的微平面（microfacet）中，同时被入射方向和反射方向可见（没有被遮挡的）的比例，
 * gi t即未被遮挡的m= h微表面的百分比。
 * @param l 交点->光源
 * @param N 法线
 * @param v 交点->眼睛
 * @return float 
 */
float Material::GeometryShadow(const Vector3f &l, const Vector3f &N, const Vector3f &v)
{

    float G_1 = 0, G_2 = 0;
    float roughness_2 = roughness * roughness;
    float n_dot_l = N.dot(l);
    float n_dot_v = N.dot(v);

    int flag_geo_1 = 0; // 主流使用Smith
    int flag_geo_2 = 0; // 主流使用Smith
    // Smith [1967]
    if (flag_geo_1 == 0)
    {
        G_1 = Physics::MathMethods::IsPositve(n_dot_v);
    }
    // Beckmann公式
    if (flag_geo_1 == 1)
    {
    }
    // Schlick-Beckmann，Schlick-GGX公式(最主流)
    if (flag_geo_1 == 2)
    {
    }

    // GGX公式（Disney方法）
    if (flag_geo_1 == 3)
    {
        float alpha_GGX = (0.5 + roughness / 2) * (0.5 + roughness / 2);
        float alpha_GGX_2 = alpha_GGX * alpha_GGX;
        float frac_below = n_dot_v + std::sqrt(alpha_GGX_2 + (1 - alpha_GGX_2) * n_dot_v * n_dot_v);
        G_1 = 2 * n_dot_v / frac_below;
    }

    // UE4的GGX-Smith Correlated Joint 近似方案
    if (flag_geo_2 == 0)
    {
        float lambda_v = n_dot_l * (n_dot_v * (1 - roughness_2) + roughness_2);
        float lambda_l = n_dot_v * (n_dot_l * (1 - roughness_2) + roughness_2);
        G_2 = 0.5 / (lambda_v + lambda_l);
    }
    // Unity HDRP 的GGX-Smith Correlated Joint近似方案
    if (flag_geo_2 == 1)
    {
        float roughness_2 = roughness * roughness;
        float lambda_v = n_dot_l * (n_dot_v * (1 - roughness) + roughness);
        float sqrt_base = (-n_dot_l * roughness_2 + n_dot_l) * n_dot_l + roughness_2;
        float lambda_l = n_dot_v * std::sqrt(sqrt_base);
        G_2 = 0.5 / (lambda_v + lambda_l);
    }

    // Google Filament渲染器 的GGX-Smith Joint近似方案
    if (flag_geo_2 == 2)
    {
        float roughness_2 = roughness * roughness;
        float sqrt_base_l = (-n_dot_l * roughness_2 + n_dot_l) * n_dot_l + roughness_2;
        float lambda_l = n_dot_v * std::sqrt(sqrt_base_l);
        float sqrt_base_v = (-n_dot_v * roughness_2 + n_dot_v) * n_dot_v + roughness_2;
        float lambda_v = n_dot_l * std::sqrt(sqrt_base_v);
        G_2 = 0.5 / (lambda_v + lambda_l);
    }

    // [2017]Respawn Entertainment的 GGX-Smith Joint近似方案
    if (flag_geo_2 == 3)
    {
        float roughness_2 = roughness * roughness;
        float sqrt_base_l = (-n_dot_l * roughness_2 + n_dot_l) * n_dot_l + roughness_2;
        float lambda_l = n_dot_v * std::sqrt(sqrt_base_l);
        float sqrt_base_v = (-n_dot_v * roughness_2 + n_dot_v) * n_dot_v + roughness_2;
        float lambda_v = n_dot_l * std::sqrt(sqrt_base_v);
        G_2 = 0.5 / (lambda_v + lambda_l);
    }
    return G_1 + G_2;
}

float FCookTorrance(const Vector3f &wi, const Vector3f &N, const Vector3f &v)
{
    Vector3f h = (-wi + v).normalized();
}
/**
 * @brief lambert光照模型
 *
 * @param wi 光->交点
 * @param N 表面法线
 * @return float 返回在wi入射角度下，N表面接受到的能量占比系数
 */
float Material::Lambert(const Vector3f &wi, const Vector3f &N)
{
    float c = 1.0f;
    float costheta = -wi.dot(N);
    if (costheta < EPSILON)
    {
        return 0.0f;
    }
    return c * costheta;
}
/**
 * @brief 使用Phong光照模型
 * Phong的高光是通过出射角和入射角的夹角计算的
 * @param wi 光->交点
 * @param N 表面法线
 * @return std::vector<Vector3f> 返回漫反射颜色+镜面反射数组
 */
std::vector<Vector3f> Material::Phong(const Vector3f &wi, const Vector3f &N)
{
    // 漫反射
    float costheta_i = -wi.dot(N);
    if (costheta_i < EPSILON)
    {
        costheta_i = 1;
    }

    Vector3f diffuse = costheta_i * kd;

    // 镜面反射
    Vector3f wo = Physics::Optics::GetReflect(wi, N);

    float costheta_o = N.dot(wo);

    if (costheta_o < EPSILON)
    {
        costheta_o = 0;
    }

    Vector3f specular = std::pow(costheta_o, exp) * ks;

    return {diffuse, specular};
}

/**
 * @brief 使用Blinn-Phong光照模型
 *
 * @param wi 光线->交点
 * @param N 表面法线方向
 * @param v 交点->眼睛
 * @return std::vector<Vector3f> 返回漫反射颜色+镜面反射数组
 */
std::vector<Vector3f> Material::BlingPhong(const Vector3f &wi, const Vector3f &N, const Vector3f &v)
{
    // 漫反射
    float costheta_i = -wi.dot(N);
    if (costheta_i < EPSILON)
    {
        costheta_i = 1;
    }
    Vector3f diffuse = costheta_i * kd;

    // 镜面反射
    Vector3f halfVec = (-wi + v).normalized();
    float costheta_h = N.dot(halfVec);
    if (costheta_h < EPSILON)
    {
        costheta_h = 0;
    }
    Vector3f specular = std::pow(costheta_h, exp) * ks;

    //总体描述
    return {diffuse, specular};
}

// TODO 对于入射该材质的每道wi，得到其入射的概率为
float Material::GetBrdfSample(const Vector3f &wi, const Vector3f &N, const Vector3f &wo)
{
    if (wo.dot(N) > 0.f)
    {
        switch (this->mt)
        {
        case DIFFUSAL:
            // return MaterialPdf::uniformlyPdf;
            return 0.5f / M_PI;
            break;
        case MIRROR:
            // return MaterialPdf::specularPdf;
            return 1.0f;
            break;
        case IRREGULAR:
            // 各项异性材料每个方向的反射概率不一致
            return MaterialPdf::importancePdf;
            break;
        default:
            // return MaterialPdf::uniformlyPdf;
            return 0.5f / M_PI;
            break;
        }
    }
    return 0.f;
}

/**
 * @brief 逆光路地计算光线传播的能量损耗
 *
 * @param wi 视线->交点
 * @param N 法线
 * @param wo 交点->出射
 * @return Vector3f
 */
Vector3f Material::EnergyEval(const Vector3f &wi, const Vector3f &N, const Vector3f &wo)
{
    if (wo.dot(N) > 0.f)
    {
        switch (this->mt)
        {
        case DIFFUSAL:
            // lambert项损耗，传播距离损耗（CastRay计算），俄罗斯轮盘概率损耗，球面采样概率损耗
            return this->kd * Lambert(-wo, N) / M_PI;

        case MIRROR:
            // FIXME 这里的除pi到底是为什么？？？？？？？
            return Vector3f(1.f, 1.f, 1.f) * Physics::Optics::Fresnel(-wo, N, this->IOR) * Lambert(-wo, N) / M_PI;
            break;

        default:
            return this->kd * Lambert(-wo, N) / M_PI;
        }
    }
    return {0.f, 0.f, 0.f};
}

Vector3f Material::DisneyEval(const Vector3f &wi, const Vector3f &N, const Vector3f &wo)
{
    float VoH;
    if (wo.dot(N) > 0.f)
    {
        float F_D90 = 0.5 + 2 * VoH * VoH * roughness;
    }
}

/**
 * @brief 基于真实物理模型的反射模型，
 *
 * @param wi 光源->交点
 * @param N 表面法线
 * @param wo 出射光线
 * @return Vector3f
 */
Vector3f Material::PhysicalEval(const Vector3f &wi, const Vector3f &N, const Vector3f &wo)
{
    // 吸收，反射，透射必须满足能量守恒关系
    if ((absorptivity + reflectivity + transmissivity) != 1)
    {
        return {0, 0, 0};
    }

    // 计算吸收损耗
    if (absorptivity > 0)
    {
    }

    // 计算反射损耗
    if (reflectivity > 0)
    {
        // GetRandomReflect(wi, N);

        // 反射之后的能量占比
        float reflectEnergyRatio = Physics::Optics::Fresnel(wi, N, this->IOR);
    }

    // 计算折射损耗
    if (IOR > 0)
    {
        // 折射方向
        Physics::Optics::GetReflect(wi, N);

        // 折射的能量占比
        float refractEnergyRatio = 1 - Physics::Optics::Fresnel(wi, N, this->IOR);
    }

    // 计算透射损耗
    if (transmissivity > 0)
    {
    }

    // 反射方向
    Physics::Optics::GetReflect(wi, N);
    return {0, 0, 0};
}
