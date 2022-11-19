#include "BoundBox.hpp"
#include "global.hpp"

/**
 * @brief 默认构造方法，pMax(min,min,min)，pMin(max,max,max)。
 *
 */
BoundBox::BoundBox()
{
    float minNum = std::numeric_limits<float>::lowest(); // lowest和min的区别在于，lowest是负数，min是最接近0的数
    float maxNum = std::numeric_limits<float>::max();

    //这样做是为了使得下一次更新pMax和pMin时，2个点都会发生改变
    pMax = Vector3f(minNum, minNum, minNum);
    pMin = Vector3f(maxNum, maxNum, maxNum);

    // GetVolumnAndArea();
}

/**
 * @brief 包围盒2点构造方法
 *
 * @param p1
 * @param p2
 */
BoundBox::BoundBox(const Vector3f &p1, const Vector3f &p2)
{
    pMax = Vector3f(std::max(p1.x(), p2.x()), std::max(p1.y(), p2.y()), std::max(p1.z(), p2.z()));
    pMin = Vector3f(std::min(p1.x(), p2.x()), std::min(p1.y(), p2.y()), std::min(p1.z(), p2.z()));
    GetVolumnAndArea();
}

/**
 * @brief 将该包围盒合并为一个包围盒
 *
 * @param bb
 * @return BoundBox
 */
BoundBox BoundBox::operator+(const BoundBox &bb)
{
    BoundBox rslt;
    rslt.pMin.x() = std::min(this->pMin.x(), bb.pMin.x());
    rslt.pMin.y() = std::min(this->pMin.y(), bb.pMin.y());
    rslt.pMin.z() = std::min(this->pMin.z(), bb.pMin.z());

    rslt.pMax.x() = std::max(this->pMin.x(), bb.pMin.x());
    rslt.pMax.y() = std::max(this->pMin.y(), bb.pMin.y());
    rslt.pMax.z() = std::max(this->pMin.z(), bb.pMin.z());

    return rslt;
}

/**
 * @brief 将该包围盒与一个点构造一个新的包围盒
 *
 * @param p
 * @return BoundBox
 */
BoundBox BoundBox::operator+(const Vector3f &p)
{
    BoundBox rslt;
    rslt.pMin.x() = std::min(this->pMin.x(), p.x());
    rslt.pMin.y() = std::min(this->pMin.y(), p.y());
    rslt.pMin.z() = std::min(this->pMin.z(), p.z());

    rslt.pMax.x() = std::max(this->pMin.x(), p.x());
    rslt.pMax.y() = std::max(this->pMin.y(), p.y());
    rslt.pMax.z() = std::max(this->pMin.z(), p.z());

    return rslt;
}

/**
 * @brief 获取当前AABB包围盒的最广的那个方向对应的坐标轴
 *
 * @return int 1表示x轴，2表示y轴，3表示z轴
 */
int BoundBox::GetAxisOfMaxExtent() const
{
    Vector3f d = GetDiagonal();
    if (d.x() > d.y() && d.x() > d.z())
    {
        return 1;
    }
    else if (d.y() > d.z())
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

/**
 * @brief 获取包围盒对角线
 *
 * @return Vector3f
 */
Vector3f BoundBox::GetDiagonal() const
{
    return pMax - pMin;
}

/**
 * @brief 获取包围盒中心点
 *
 * @return Vector3f
 */
Vector3f BoundBox::GetCentroid() const
{
    return 0.5 * (pMin + pMax);
}

/**
 * @brief 包围盒是否与光线相交核心算法，liang-barsky算法
 *
 * @param ray
 * @return true
 * @return false
 */
bool BoundBox::IsIntersect(const Ray &ray) const
{

    // 初始化参数列表：光线进入时间和离开时间
    float tEnter = std::numeric_limits<float>::min();
    float tExit = std::numeric_limits<float>::max();

    // Vector3f dirInv(1 / ray.direction.x(), 1 / ray.direction.y(), 1 / ray.direction.z());
    //  Vector3i dirIsNagtive(ray.direction.x() <= 0, ray.direction.y() <= 0, ray.direction.z() <= 0);

    // 每个包围盒视为3对平面，对每个坐标轴方向的分量的分别计算包围盒的进入时间和离开时间
    // pair[0]对应x轴，pair[1]对应y轴，pair[2]对应z轴
    for (int pair = 0; pair < 3; ++pair)
    {

        // 保存光线在pair分量上，与包围盒的最小相交时间tMin和最大相交时间tMax
        float tMin = 0.f, tMax = 0.f;

        // 遍历pMin和pMax的x，y，z方向上的分量，计算每个分量到达平面的时间
        // 保存所有pair里的最大进入时间和最小离开时间
        // tMin = (pMin[pair] - ray.origin[pair]) * dirInv[pair];
        // tMax = (pMax[pair] - ray.origin[pair]) * dirInv[pair];

        // 根据公式r(t)=o+t*dir，得到当前ray在pair分量上的最小、最大相交时间

        tMin = (this->pMin[pair] - ray.origin[pair]) / ray.direction[pair];
        tMax = (this->pMax[pair] - ray.origin[pair]) / ray.direction[pair];

        // 若坐标轴上的光线方向为负，则从pmax进入，pmin离开，交换 tmin和tmax
        if (ray.direction[pair] <= 0)
        {
            std::swap(tMin, tMax);
        }

        // 使用当前分量的进入、离开时间，更新整个包围盒的最晚进入时间和最早离开时间
        tEnter = std::max(tEnter, tMin);
        tExit = std::min(tExit, tMax);

        // printf("tMin:%f, tMax:%f, tEnter:%f, tExit:%f;\n", tMin, tMax, tEnter, tExit);
    }

    // 根据最早进入时间tEnter和最晚离开时间tExit，判断光线是否与包围盒相交
    // printf("pMin:[%f,%f,%f], pMax:[%f,%f,%f], tEnter:%f, tExit:%f \n", this->pMin.x(), this->pMin.y(), this->pMin.z(), this->pMax.x(), this->pMax.y(), this->pMax.z(), tEnter, tExit);
    return tEnter <= tExit && tExit >= 0;
}