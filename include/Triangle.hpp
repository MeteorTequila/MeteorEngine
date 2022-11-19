
#pragma once

#include "Object.hpp"
#include "Acceleration.hpp"

struct Vertex
{
    // 顶点坐标
    Vector3f position;

    // 顶点法线
    Vector3f normal;

    // 顶点纹理坐标
    Vector2f textureCoordinate;
};

class Triangle : public Object
{
public:
    Vector3f p0, p1, p2; //三点坐标
    Vertex v0, v1, v2;   //顶点坐标
    float area;          //面积
    Vector3f normal;     //法线
    Material *m;         //材质

    // Triangle();
    Triangle(Vector3f &_v0, Vector3f &_v1, Vector3f &_v2, Material *_m = nullptr);

    float GetArea() override;

    bool HasEmission() const override;

    Intersection GetRayIntersection(const Ray &ray) override;

    BoundBox GetBoundBox() override;

    void GetSample(Intersection &pos, float &pdf) override;

    Vector3f GetNormal();

private:
};
