#include "Acceleration.hpp"
#include "global.hpp"

/**
 * @brief 预处理加速器，构建加速结构
 *
 * @param objects 场景对象容器
 * @param at 加速方法
 */
Acceleration::Acceleration(std::vector<Object *> objects, AccelType at)
{
  switch (at)
  {
  case BVH:
    root = BuildBVHTree(objects);
    break;
  case SAH:
    break;
  case kdTree:
    break;
  default:
    break;
  }
}

/**
 * @brief 划分算法，将父容器内物体按照最长轴排序，返回两个子容器
 *
 * @param objects 待排序容器
 * @return std::vector<std::vector<Object *>> 返回object的左右部分
 */
std::vector<std::vector<Object *>> Acceleration::Partition(std::vector<Object *> objects)
{
  // 将当前递归中的所有对象合并到一个包围盒里面，获取包围盒的最长轴
  BoundBox bb;
  for (int i = 0; i < objects.size(); ++i)
  {
    bb = Merge(bb, objects[i]->GetBoundBox().GetCentroid());
  }
  int axis = bb.GetAxisOfMaxExtent();

  // 将最大包围盒内object按照最长轴递增的顺序排列
  switch (axis)
  {
  case 1:
    std::sort(objects.begin(), objects.end(), [](Object *f1, Object *f2)
              { return f1->GetBoundBox().GetCentroid().x() < f2->GetBoundBox().GetCentroid().x(); });
    break;
  case 2:
    std::sort(objects.begin(), objects.end(), [](Object *f1, Object *f2)
              { return f1->GetBoundBox().GetCentroid().y() < f2->GetBoundBox().GetCentroid().y(); });
    break;
  case 3:
    std::sort(objects.begin(), objects.end(), [](Object *f1, Object *f2)
              { return f1->GetBoundBox().GetCentroid().z() < f2->GetBoundBox().GetCentroid().z(); });
    break;
  }

  // partition操作，将包围盒内的物体划分为左右部分
  std::vector<Object *>::iterator begin = objects.begin();
  std::vector<Object *>::iterator middle = objects.begin() + objects.size() / 2;
  std::vector<Object *>::iterator end = objects.end();
  std::vector<Object *> leftPart(begin, middle);
  std::vector<Object *> rightPart(middle, end);

  // 检查划分的是否有错误，有则不会执行后续程序
  assert(objects.size() == (leftPart.size() + rightPart.size()));

  return {leftPart, rightPart};
}

/**
 * @brief 递归构造BVH树
 * 包含两个递归操作的并行过程
 * 递归栈入栈时，执行objects容器划分操作，最终每个子容器将只有1个或者2个元素。
 * 递归栈出栈时，用每个子容器从下往上创建bvh树节点
 * @param objects 场景的对象指针数组
 * @return BVHNode* BVH树节点
 */
BVHNode *Acceleration::BuildBVHTree(std::vector<Object *> objects)
{
  BVHNode *node = new BVHNode();

  BoundBox b;

  // 将objects中的所有对象都合并为一个包围盒
  for (int i = 0; i < objects.size(); ++i)
  {
    b = Merge(b, objects[i]->GetBoundBox());
  }

  if (objects.size() == 1)
  {
    // 若子容器只有1个object，创建叶子结点
    node->box = objects[0]->GetBoundBox();
    node->object = objects[0];
    node->area = objects[0]->GetArea();

    node->left = nullptr;
    node->right = nullptr;


    return node;
  }
  else if (objects.size() == 2)
  {
    // 若子容器有2个object，创建非叶子结点

    node->left = BuildBVHTree(std::vector{objects[0]});
    node->right = BuildBVHTree(std::vector{objects[1]});

    node->box = Merge(node->left->box, node->right->box);
    node->area = node->left->area + node->right->area;

    return node;
  }
  else
  {
    // 递归的执行划分操作，并将划分后的容器插入到bvh树的子节点上
    // 划分为左右两部分
    auto leftPart = Partition(objects)[0];
    auto rightPart = Partition(objects)[1];

    node->left = BuildBVHTree(leftPart);
    node->right = BuildBVHTree(rightPart);

    node->box = Merge(node->left->box, node->right->box);
    node->area = node->left->area + node->right->area;
  }
  //返回根节点
  return node;
}

/**
 * @brief 递归查找光线与以该节点为根节点的bvh树的焦点
 *
 * @param ray 光线
 * @param root bvh节点
 * @return Intersection
 */
Intersection Acceleration::AccQueryIntersection(BVHNode *node, const Ray &ray) const
{
  Intersection inter;

  // 每次进入递归，首先判断是否与当前节点最外层包围盒相交，若不相交，那么说明与该节点内的任何物体都没有相交
  if (!node->box.IsIntersect(ray))
  {
    return inter;
  }

  // 如果当前节点是叶子结点，那么当前节点中物体的的相交事件就是最终需要返回的结果
  if (!node->left && !node->right)
  {
    return node->object->GetRayIntersection(ray);
  }

  // 如果当前节点不是叶子结点，那么就向下遍历孩子节点，直至到叶子节点
  Intersection leftInter = AccQueryIntersection(node->left, ray);
  Intersection rightInter = AccQueryIntersection(node->right, ray);

  // 递归栈出栈，光线传播最小的distance是首次相交的位置
  return leftInter.distance < rightInter.distance ? leftInter : rightInter;
}

/**
 * @brief 获取光线与加速结构上物体的相交事件
 *
 * @param ray
 * @return Intersection 光线相交事件
 */
Intersection Acceleration::GetIntersection(const Ray &ray) const
{

  Intersection inter;

  // 如果bvh树为空，则不做相交判断
  if (!root)
  {
    return inter;
  }

  // 判断光线是否与bvh上的object相交
  return AccQueryIntersection(root, ray);
}

/**
 * @brief 在加速结构上递归的遍历，快速定位发光区域，从而对其采样
 *
 * @param node 加速节点
 * @param p 随机数，控制向下方向
 * @param pos 发光区域坐标
 * @param pdf 发光区域采样概率
 */
void Acceleration::AccGetSample(BVHNode *node, float p, Intersection &pos, float &pdf)
{
  // 如果当前节点为叶子结点，那么包围盒内的物体就是要采样的对象
  if (node->left == nullptr || node->right == nullptr)
  {
    node->object->GetSample(pos, pdf);
    pdf *= node->area;
    return;
  }

  // 随机向左右子树递归
  if (p < node->left->area)
  {
    AccGetSample(node->left, p, pos, pdf);
  }
  else
  {
    // 如果p>area(left)，那么p=p-area(left)
    AccGetSample(node->right, p - node->left->area, pos, pdf);
  }
}

/**
 * @brief 通过加速结构得到采样，通过形参返回值
 *
 * @param pos 发光区域坐标【返回】
 * @param pdf 发光区域采样概率【返回】
 */
void Acceleration::GetSample(Intersection &pos, float &pdf)
{
  // 随机sqrt(rd)*sum(area)
  float p = std::sqrt(get_random_float()) * root->area;

  //
  AccGetSample(root, p, pos, pdf);

  // pdf=1/sum(area)
  pdf /= root->area;
}