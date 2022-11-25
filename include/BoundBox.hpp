#ifndef METEOR_BOUNDBOX_H
#define METEOR_BOUNDBOX_H

#include "Eigen/Eigen"

#include "Ray.hpp"

using namespace Eigen;

class BoundBox
{
public:
    Vector3f pMin, pMax; //包围盒的最小点和最大点

    float volume, surfaceArea;

    BoundBox();

    BoundBox(const Vector3f &p1, const Vector3f &p2);

    Vector3f GetDiagonal() const;

    Vector3f GetCentroid() const;

    int GetAxisOfMaxExtent() const;

    BoundBox operator+(const BoundBox &bb);
    BoundBox operator+(const Vector3f &p);

    BoundBox Merge(const BoundBox &bb);
    BoundBox Merge(const Vector3f &p);

    bool IsIntersect(const Ray &ray) const;

    // FIXME 测试用

    void GetVolumnAndArea()
    {
        volume = (pMax.x() - pMin.x()) * (pMax.y() - pMin.y()) * (pMax.z() - pMin.z());
        surfaceArea = (pMax.x() - pMin.x()) * (pMax.y() - pMin.y()) * 2 + (pMax.x() - pMin.x()) * (pMax.z() - pMin.z()) * 2 + (pMax.y() - pMin.y()) * (pMax.z() - pMin.z()) * 2;
    }

    void ToString()
    {
        printf("area: %f, volumn: %f, pMin[%f, %f, %f], pMax[%f, %f, %f]\n", surfaceArea, volume, this->pMin.x(), this->pMin.y(), this->pMin.z(), this->pMax.x(), this->pMax.y(), this->pMax.z());
    };
};

/**
 * @brief 两个包围盒的并方法
 *
 * @param b1
 * @param b2
 * @return BoundBox
 */
inline BoundBox Merge(const BoundBox &b1, const BoundBox &b2)
{
    BoundBox rslt;
    rslt.pMin.x() = std::min(b1.pMin.x(), b2.pMin.x());
    rslt.pMin.y() = std::min(b1.pMin.y(), b2.pMin.y());
    rslt.pMin.z() = std::min(b1.pMin.z(), b2.pMin.z());

    rslt.pMax.x() = std::max(b1.pMax.x(), b2.pMax.x());
    rslt.pMax.y() = std::max(b1.pMax.y(), b2.pMax.y());
    rslt.pMax.z() = std::max(b1.pMax.z(), b2.pMax.z());

    return rslt;
}

/**
 * @brief 包围盒与一个点并
 *
 * @param b
 * @param p
 * @return BoundBox
 */
inline BoundBox Merge(const BoundBox &b, const Vector3f &p)
{
    BoundBox rslt;
    rslt.pMin.x() = std::min(b.pMin.x(), p.x());
    rslt.pMin.y() = std::min(b.pMin.y(), p.y());
    rslt.pMin.z() = std::min(b.pMin.z(), p.z());

    rslt.pMax.x() = std::max(b.pMax.x(), p.x());
    rslt.pMax.y() = std::max(b.pMax.y(), p.y());
    rslt.pMax.z() = std::max(b.pMax.z(), p.z());

    return rslt;
}
#endif