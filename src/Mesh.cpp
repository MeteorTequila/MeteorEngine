#include "Mesh.hpp"

// TODO Mesh对象到底是什么？？？？？？
/**
 * @brief 将obj文件mesh化
 *
 * @param filename 文件绝对路径
 * @param mt 每个Triangle的材质
 */
MeshTriangle::MeshTriangle(const std::string &filename, Material *mt = new Material())
{

  printf(" - 开始构造Mesh对象\n\n");

  // 载入文件名
  objl::Loader loader;
  loader.LoadFile(filename);

  // 初始化mesh三角形面积和材质
  this->area = 0;
  this->m = mt;

  // 判断文件中的模型数量是否只有1个，如果有多个模型就不执行后续的语句
  assert(loader.LoadedMeshes.size() == 1);

  // 新建mesh对象
  auto mesh = loader.LoadedMeshes[0];

  // 初始化模型的最小顶点和最大顶点
  Vector3f minV(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity());
  Vector3f maxV(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity());

  // 遍历所有的顶点，每3个顶点组成一个面
  for (int i = 0; i < mesh.Vertices.size(); i += 3)
  {
    std::array<Vector3f, 3> face_vertices;

    for (int j = 0; j < 3; ++j)
    {
      auto vert = Vector3f(mesh.Vertices[i + j].Position.X, mesh.Vertices[i + j].Position.Y, mesh.Vertices[i + j].Position.Z);

      face_vertices[j] = vert;

      minV = Vector3f(std::min(minV.x(), vert.x()), std::min(minV.y(), vert.y()), std::min(minV.z(), vert.z()));
      maxV = Vector3f(std::max(maxV.x(), vert.x()), std::max(maxV.y(), vert.y()), std::max(maxV.z(), vert.z()));
    }

    // emplace_back()在实现时，直接在容器的尾部创建这个元素，省去了拷贝或移动元素的过程。
    triangles.emplace_back(face_vertices[0], face_vertices[1], face_vertices[2], mt);
  }

  // 为当前Mesh对象构建包围盒
  this->bb = BoundBox(minV, maxV);

  std::vector<Object *> ptrs;

  // 将Mesh对象中的每个三角形片元指针装载进数组中
  for (auto &tri : triangles)
  {
    ptrs.push_back(&tri);
    area += tri.area;
  }

  //   printf("ptrs size is %lu \n\n", ptrs.size());

  // 为Mesh model构建加速结构
  this->acc = new Acceleration(ptrs);

  printf(" - Mesh对象构造完毕\n\n");
}

/**
 * @brief 对Mesh对象中的发光区域加速采样
 *
 * @param pos 发光区域位置
 * @param pdf 采样概率
 */
void MeshTriangle::GetSample(Intersection &pos, float &pdf)
{

  acc->GetSample(pos, pdf);

  // FIXME 当前材质保存在Intersection结构体中，(方便将材质的信息，如颜色，传给castRay())
  pos.m = this->m;
  // pos.emission=m->GetEmission();
}

/**
 * @brief 获取Mesh对象的光线相交事件
 *
 * @param _ray
 * @return Intersection
 */
Intersection MeshTriangle::GetRayIntersection(const Ray &_ray)
{
  return this->acc->GetIntersection(_ray);
}

/**
 * @brief 获取Mesh对象的表面积
 *
 * @return float
 */
float MeshTriangle::GetArea() { return this->area; }

/**
 * @brief 获取Mesh对象的包围盒
 *
 * @return BoundBox
 */
BoundBox MeshTriangle::GetBoundBox()
{
  return this->bb;
}

/**
 * @brief 判断Mesh对象是否能够发光
 *
 * @return true
 * @return false
 */
bool MeshTriangle::HasEmission() const
{
  return this->m->HasEmission();
}
