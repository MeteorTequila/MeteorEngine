#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(const Vector3f &_center, const float &_radius, Material *_m)
{
    this->center = _center;
    this->radius = _radius;
    this->radius2 = _radius * _radius;
    this->m = _m;
    this->area = M_PI * _radius * _radius;
}

float Sphere::GetArea()
{
    return this->area;
}

bool Sphere::HasEmission() const
{
    return this->m->HasEmission();
}

void Sphere::GetSample(Intersection &pos, float &pdf)
{
    float theta = 2.0 * M_PI * get_random_float(), phi = M_PI * get_random_float();                //定义随机theta和phi，球坐标系中的天顶角和方位角
    Vector3f dir(std::cos(phi), std::sin(phi) * std::cos(theta), std::sin(phi) * std::sin(theta)); //根据theta和phi生成一个方向向量
    pos.coords = center + radius * dir;                                                            //设置碰撞事件在球体上的坐标
    pos.normal = dir;                                                                              //相交事件的法线
    pos.emission = this->m->GetEmission();                                                         //当前材质是否可以发光
    pdf = 1.0f / area;
}

inline bool solveQuadratic(const float &a, const float &b, const float &c, float &x0, float &x1)
{
    float discr = b * b - 4 * a * c;
    if (discr < 0)
        return false;
    else if (discr == 0)
        x0 = x1 = -0.5 * b / a;
    else
    {
        float q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }
    if (x0 > x1)
        std::swap(x0, x1);
    return true;
}

Intersection Sphere::GetRayIntersection(const Ray &_ray)
{
    Intersection result;
    result.IsHappend = false;
    Vector3f L = _ray.origin - center;
    float a = _ray.direction.dot(_ray.direction);
    float b = 2 * _ray.direction.dot(L);
    float c = L.dot(L) - radius2;
    float t0, t1;
    if (!solveQuadratic(a, b, c, t0, t1))
        return result;
    if (t0 < 0)
        t0 = t1;
    if (t0 < 0)
        return result; //如果二次方程的两个解t1，t2均小于0，说明相交事件没有发生，直接返回happened=false

    // FIXME 函数中修改圆的相交判定，因为圆的相交判定精度不够。
    //若不修改，程序在运行中会报错，因为当t0=0时，有可能会造成除0错误
    // https://blog.csdn.net/weixin_44518102/article/details/122698851?spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-9.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~Rate-9.pc_relevant_default&utm_relevant_index=12

    if (t0 > 0.5)
    {
        result.IsHappend = true; //否则，相交事件发生

        //将相交事件的结果保存在result里
        result.coords = Vector3f(_ray.origin + _ray.direction * t0); //使用射线公式，返回相交坐标
        result.normal = Vector3f(result.coords - center).normalized();
        result.m = this->m;   //材质直接用当前object对象的公有属性
        result.object = this; //当前对象
        result.distance = t0; //相交距离
    }

    return result;
}

BoundBox Sphere::GetBoundBox()
{
    return BoundBox(Vector3f(center.x() - radius, center.y() - radius, center.z() - radius),
                    Vector3f(center.x() + radius, center.y() + radius, center.z() + radius));
}