
#ifndef METEOR_MESH_H
#define METEOR_MESH_H

#include "Triangle.hpp"
#include "OBJ_Loader.hpp"

/**
 * @brief Mesh对象，将obj文件存储在Mesh对象里，Mesh对象由多个Triangle组成
 *
 */
class MeshTriangle : public Object
{
public:
    std::vector<Triangle> triangles; // Mesh对象的Triangle片元

    Acceleration *acc; //加速结构

    BoundBox bb;

    float area;

    Material *m;

    MeshTriangle(const std::string &filename, Material *mt);

    Intersection GetRayIntersection(const Ray &_ray) override;

    BoundBox GetBoundBox() override;

    float GetArea() override;

    bool HasEmission() const override;

    void GetSample(Intersection &pos, float &pdf) override;
};

#endif