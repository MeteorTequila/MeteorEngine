#include "Triangle.hpp"
#include "BoundBox.hpp"
#include "global.hpp"

//构造函数，初始化顶点，计算面积
Triangle::Triangle(Vector3f &_v0, Vector3f &_v1, Vector3f &_v2, Material *_m)
{
    p0 = _v0;
    p1 = _v1;
    p2 = _v2;
    m = _m;

    area = ((p1 - p0).cross(p2 - p0)).norm() * 0.5f; //面积公式

    normal = ((p1 - p0).cross(p2 - p0)).normalized(); //获取三角形法向量

    // 顶点结构初始化
    v0.position = _v0;
    v1.position = _v1;
    v2.position = _v2;

    v0.normal = normal;
    v1.normal = normal;
    v2.normal = normal;
}

bool Triangle::HasEmission() const
{
    return this->m->HasEmission();
}

// 获取面积
float Triangle::GetArea()
{
    return area;
}

// 获取表面法线
Vector3f Triangle::GetNormal()
{
    return normal;
}

// 创建一个包围盒
BoundBox Triangle::GetBoundBox()
{
    // FIXME 包围盒的pMin和pMax没有保存
    // Merge(BoundBox(p0, p1), p2).ToString();
    return Merge(BoundBox(p0, p1), p2);
    // return BoundBox(p0, p1) + p2;
}

/**
 * @brief 判断给定射线是否与当前三角形相交
 *
 * @param ray 给定射线
 * @return Intersection
 */
Intersection Triangle::GetRayIntersection(const Ray &ray)
{
    Intersection inter;

    /* -----------------这里使用moiiller Trumbore Algorithm----------------- */

    // 定义算法需要的参数
    Vector3f E_1;
    Vector3f E_2;
    Vector3f S;
    Vector3f S_1;
    Vector3f S_2;

    // TODO EPSILON的精度设置，判断光线方向？如果是玻璃球内部弹射，这个不应该被设置，
    E_1 = p1 - p0;
    E_2 = p2 - p0;
    S = ray.origin - p0;
    S_1 = ray.direction.cross(E_2);
    S_2 = S.cross(E_1);

    // 如果算法的分母太小，会导致最后的结果很大，则认为不相交
    if (S_1.dot(E_1) < EPSILON)
    {
        return inter;
    }

    // 计算moiiller Trumbore Algorithm，得到射线相交的时间和交点重心坐标
    Vector3f rslt = (1 / S_1.dot(E_1)) * Vector3f(S_2.dot(E_2), S_1.dot(S), S_2.dot(ray.direction));

    // 如果得到的u=rslt.y() v=rslt.z()不满足重心坐标的性质，则没有发生相交
    if (rslt.y() < 0 || rslt.z() < 0 || (rslt.y() + rslt.z()) > 1)
    {
        return inter;
    }
    // 保存当前相交信息
    inter.IsHappend = true;
    inter.coords = ray.PosAfterT(rslt.x());
    inter.normal = normal;
    inter.distance = rslt.x();
    inter.object = this;
    inter.m = m;

    // 返回相交数据
    return inter;
}

/**
 * @brief 在当前三角形片元内随机采样一个点，得到该的坐标和采样概率
 *
 * @param pos 采样坐标（通过形参返回）
 * @param pdf 采样概率（通过形参返回）
 */
void Triangle::GetSample(Intersection &pos, float &pdf)
{
    // 随机采样得到两个数用于计算重心坐标
    float u = std::sqrt(get_random_float()), v = get_random_float();

    // 重心坐标做插值，得到三角形内的一个点（注意这里v0,v1,v2的系数加起来=1）
    pos.coords = (1.0f - u) * p0 + (u * (1.0f - v)) * p1 + (u * v) * p2;
    pos.normal = this->normal;

    // 在三角形内随机取一个点的概率
    pdf = 1.0f / area;
}
