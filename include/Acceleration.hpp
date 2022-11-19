#ifndef METEOR_ACCELERATION_H
#define METEOR_ACCELERATION_H

#include "BoundBox.hpp"
#include "Object.hpp"

// BVH树
struct BVHNode
{
  BoundBox box;   //当前节点的最大包围盒
  Object *object; //节点指向的object
  float area;     //面积

  BVHNode *left;  //左儿子
  BVHNode *right; //右儿子
};

// 加速类型
enum AccelType
{
  BVH,
  SAH,
  kdTree
};

// 结构加速器
class Acceleration
{
public:
  AccelType at;  //加速类型
  BVHNode *root; // BVH树根

  Acceleration(std::vector<Object *> objects, AccelType at = BVH);
  Intersection GetIntersection(const Ray &ray) const;
  void GetSample(Intersection &pos, float &pdf);

private:
  std::vector<std::vector<Object *>> Partition(std::vector<Object *> objects);
  BVHNode *BuildBVHTree(std::vector<Object *> objects);
  Intersection AccQueryIntersection(BVHNode *node, const Ray &ray) const;
  void AccGetSample(BVHNode *node, float p, Intersection &pos, float &pdf);
};

#endif