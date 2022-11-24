#include "Material.hpp"
#include "Intersection.hpp"
#include "Physics.hpp"
#include "Shader.hpp"
#include "global.hpp"
#include <cmath>

Material::Material()
{
    this->emission = {0, 0, 0};
    this->IOR = 1.2f;
    this->reflectivity = 0.8;
    this->transmissivity = 0;
    this->kd = {0.2f, 0.4f, 0.8f};
    this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
    this->exp = 10;

    this->baseColor = {0.2f, 0.4f, 0.8f};
};

// TODO 材质初始化方法
Material::Material(MaterialType _mt)
{
    this->mt = _mt;

    switch (_mt)
    {
    case DIFFUSAL:
    {
        this->emission = {0, 0, 0};
        this->IOR = 1.51f; //硅酸盐折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.725f, 0.71f, 0.68f};

        this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->exp = 10;

        this->baseColor = {0.725f, 0.71f, 0.68f};
        this->roughness = 0.8;

        break;
    }
    case MIRROR:
    {
        this->emission = {0, 0, 0};
        this->IOR = 1.33f; //银的折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->exp = 10;

        this->baseColor = {0.2f, 0.4f, 0.8f};
        this->roughness = 0;

        break;
    }
    case MICROFACET:
    {
        this->emission = {0, 0, 0};
        // this->IOR = 2.42; //钻石的折射率
        this->IOR = 1.85;
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        // this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->ks = {0.3f, 0.5f, 0.9f};
        this->exp = 10;

        this->baseColor = {0.2f, 0.4f, 0.8f};
        this->roughness = 0.35;
        break;
    }
    case TRANSPARENT:
    {
        this->emission = {0, 0, 0};
        this->IOR = 2.42; //钻石的折射率
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->exp = 10;

        this->baseColor = {0.2f, 0.4f, 0.8f};
        this->roughness = 0.1;
        break;
    }

    case IRREGULAR:
    {
        this->emission = {0, 0, 0};
        this->IOR = 1.2f;
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->exp = 10;

        this->baseColor = {0.2f, 0.4f, 0.8f};
        this->roughness = 0.9;

        break;
    }
    default:
    {
        this->emission = {0, 0, 0};
        this->IOR = 1.2f;
        this->reflectivity = 0.8;
        this->transmissivity = 0;
        this->kd = {0.2f, 0.4f, 0.8f};
        this->ks = Vector3f(1.0f, 1.0f, 1.0f) - this->kd;
        this->exp = 10;

        this->baseColor = {0.2f, 0.4f, 0.8f};
        this->roughness = 0.8;
        break;
    }
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
 * @param wi 入射方向
 * @param N 表面法线
 * @return Vector3f 随机的出射方向
 */
Vector3f Material::GetRandomReflect(const Vector3f &wi, const Vector3f &N)
{
    // 不同的随机办法
    int sample_flag = 0;

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
 * @param N 表面法线
 * @param h 光源方向与人眼方向的半程向量
 * @return float [0.0, 1.0]
 */
float Material::DistributionOfNormal(const Vector3f &N, const Vector3f &h)
{
    float n_dot_h = N.dot(h) > 0.f ? N.dot(h) : 0.f; // N代表宏观层面的法向量，h半程向量用于表示微观层面的法向量

    // GGX分布，即Trowbridge-Reitz分布
    return ND_test(n_dot_h, roughness);

    //测试用
    // return ND_test(n_dot_h, roughness);
}

/**
 * @brief 几何函数
 * @param l 交点->光源
 * @param N 法线
 * @param v 交点->眼睛
 * @return float [0.0, 1.0]
 */
float Material::GeometryShadow(const Vector3f &l, const Vector3f &N, const Vector3f &v)
{
    float n_dot_l = N.dot(l) > 0.f ? N.dot(l) : 0.f;
    float n_dot_v = N.dot(v) > 0.f ? N.dot(v) : 0.f;

    // UE4的GGX-Smith Correlated Joint 近似方案
    // return G_Smith_UE4(n_dot_v, n_dot_l, roughness);

    //测试用
    return G_Test(n_dot_v, n_dot_l, roughness);
}

/**
 * @brief lambert光照模型
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

    Vector3f diffuse = costheta_i * this->baseColor;

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
    Vector3f diffuse = costheta_i * this->baseColor;

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

/**
 * @brief 使用Cook-Torrance模型计算更为真实的反射高光
 * @param toL 交点->光源
 * @param N 法线
 * @param wo 交点->反射
 * @param eye 交点->眼睛
 * @return float
 */
float Material::CookTorranceSpecular(const Vector3f &L, const Vector3f &N, const Vector3f &V)
{

    Vector3f H = (L + V).normalized();
    float ND_term = DistributionOfNormal(N, H); //法线分布
    float G_term = GeometryShadow(L, N, V);     //几何阴影

    // printf("D: %f, G: %f ;", ND_term, G_term);

    float denom = 4 * std::max(L.dot(N), 0.f) * std::max(H.dot(N), 0.f);

    return ND_term * G_term / std::max(denom, EPSILON);
}
// TODO 对于入射该材质的每道-wo，得到其入射的概率为
float Material::GetBrdfSample(const Vector3f &V, const Vector3f &N, const Vector3f &L)
{
    if (L.dot(N) > 0.f)
    {
        switch (this->mt)
        {
        case DIFFUSAL:
        {
            // return MaterialPdf::uniformlyPdf;
            return 0.5f / M_PI;
            break;
        }
        case MICROFACET:
        {
            // return MaterialPdf::uniformlyPdf;
            return 0.5f / M_PI;
            break;
        }
        case MIRROR:
        {
            // return MaterialPdf::specularPdf;
            return 1.0f;
            break;
        }
        case IRREGULAR:
        {
            // 各项异性材料每个方向的反射概率不一致
            return MaterialPdf::importancePdf;
            break;
        }
        default:
        {
            // return MaterialPdf::uniformlyPdf;
            return 0.5f / M_PI;
            break;
        }
        }
    }
    return 0.f;
}

/**
 * @brief 逆光路地计算光线传播的能量损耗
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
        {
            // lambert项损耗，传播距离损耗（CastRay计算），俄罗斯轮盘概率损耗，球面采样概率损耗
            return this->baseColor * Lambert(-wo, N) / M_PI;
        }

        case MIRROR:
        {
            // 这里的除pi到底是为什么？？？？？？？
            // 因为偏导数 https://zhuanlan.zhihu.com/p/342807202
            return Vector3f(1.f, 1.f, 1.f) * Physics::Optics::Fresnel(-wo, N, this->IOR) * Lambert(-wo, N) / M_PI;
            break;
        }

        case MICROFACET:
        {

            Vector3f diffuse = this->baseColor * Lambert(-wo, N) / M_PI;
            // FIXME高光颜色过强
            Vector3f specular = this->ks * CookTorranceSpecular(wo, N, -wi);

            // 能量守恒
            Vector3f rRatio = Physics::Optics::FresnelSchlick(-wo, N, this->IOR);

            Vector3f tRatio = Vector3f(1.f, 1.f, 1.f) - rRatio;

            return tRatio.cwiseProduct(diffuse) + rRatio.cwiseProduct(specular);
            // return rRatio.cwiseProduct(specular);
        }

        default:
            return this->baseColor * Lambert(-wo, N) / M_PI;
        }
    }
    return {0.f, 0.f, 0.f};
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
