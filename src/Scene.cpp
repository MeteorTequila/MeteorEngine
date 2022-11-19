#include "Scene.hpp"
#include "Acceleration.hpp"
#include "eigen-3.4.0/Eigen/Eigen"
#include "global.hpp"

// 通过width和height构造场景
Scene::Scene(int w, int h)
{
  printf("\n - 长为 %d 宽为 %d 的场景初始化中... \n\n", w, h);
  this->width = w;
  this->height = h;
}

/**
 * @brief 对场景中的物体进行预处理
 * TODO 对场景中的物体做预处理，为每个物体创建包围盒
 */
void Scene::PreProcessing()
{
  // 使其能够高效查询，需要BVH加速，构建BVH树
  // 对场景中的物体建立AABB包围盒，并且为包围盒构建加速结构，并且其根节点acc->root;
  printf(" - 为场景中的物体构建加速的AABB包围盒 \n\n");

  this->acc = new Acceleration(objects, BVH);

  // 对场景中的物体采样
}

// 向场景中添加对象
void Scene::add(Object *object)
{
  objects.push_back(object);
  printf(" - 添加物体成功，当前场景内物体数量为%lu \n\n", objects.size());
}

/**
 * @brief 判断射线是否与场景中的物体有相交
 *
 * @param ray 射线
 * @return Intersection 相交事件
 */
Intersection Scene::GetIntersection(const Ray &ray) const
{
  return this->acc->GetIntersection(ray);
}

/**
 * @brief 对场景中的所有发光区域平均采样
 * 路径追踪中，因为反射方向是随机的，所以EyeRay弹射后很有可能无法回到光源
 * 为了提高效率，可以在溯源光线时主动地抽样发光物体。
 * @param pos (返回)采样光源位置
 * @param pdf (返回)采样概率
 */
void Scene::GetEmissionSample(Intersection &pos, float &pdf) const
{
  float sumEmitArea = 0;

  //遍历场景中的所有Triangle片元，判断Material是否能发光
  for (uint32_t k = 0; k < objects.size(); ++k)
  {
    //如果能够发光，累加所有发光material的面积
    if (objects[k]->HasEmission())
    {
      sumEmitArea += objects[k]->GetArea();
    }
  }
  //随机取[0,emit_area_sum]之间的一个数p
  float p = get_random_float() * sumEmitArea;
  sumEmitArea = 0;

  //开始对场景中的发光体进行第二次遍历，只要第二次遍历中的sumEmitArea>p就对当前发光区域采样
  for (uint32_t k = 0; k < objects.size(); ++k)
  {
    if (objects[k]->HasEmission())
    {
      sumEmitArea += objects[k]->GetArea();
      if (p <= sumEmitArea)
      {
        //对第当前object采样
        objects[k]->GetSample(pos, pdf);

        break;
      }
    }
  }
}

/**
 * @brief 路径追踪，在场景中递归的发射光线
 * 一道光线由摄像机发射往像素，之后自动递归的向场景中其他方向发射光线
 * @param ray EyeRay或者ReflectRay或者RefractRay
 * @return Vector3f
 */
Vector3f Scene::CastRay(const Ray &ray) const
{

  // 总共发射次1024*1024*（2+2+2+2）*2=9834496直接光照
  Vector3f l_dir(0.f, 0.f, 0.f);
  Vector3f l_indir(0.f, 0.f, 0.f);

  // 从摄像机角度发射EyeRay，与场景中的物体求交，判断是否能够看到场景中的物体

  Intersection inter = GetIntersection(ray);

  // 如果没发生相交，返回空
  if (!inter.IsHappend)
  {
    return {0, 0, 0};
  }

  // 如果看到的就是光源,直接返回光源颜色
  if (inter.m->HasEmission())
  {
    // FIXME 要计算距离衰减
    // float decay_inter_2 = 1 / inter.distance / inter.distance;
    // return decay_inter_2 * inter.m->GetEmission();

    // return inter.m->GetEmission();
    return inter.m->GetEmission() / LAMBDA;
  }

  /**
   * ----------------------------------------------------------------------------------------------------------------
   * ------------------------------------- 直接光照（光源是否能够直接照射到物体）-------------------------------------------
   * ----------------------------------------------------------------------------------------------------------------
   */

  // 获取场景中的采样后的发光区域的坐标和概率,得到采样光源的位置和强度（方便直接对光源方向采样）
  // 为了提高直接光照的采样效率，直接朝场景内所有的发光体均匀采样
  Intersection emissionSample;
  float emissionSamplePdf;
  GetEmissionSample(emissionSample, emissionSamplePdf);
  Vector3f lightPositon = emissionSample.coords;
  Vector3f lightIntensity = emissionSample.m->GetEmission();

  // 产生EyeRay交点->样本光源的射线，并且获取相交事件
  Vector3f dir_obj_to_sample = (lightPositon - inter.coords).normalized();
  Ray ray_obj_to_sample(inter.coords, dir_obj_to_sample);
  Intersection inter_dir = GetIntersection(ray_obj_to_sample);

  // 如果ray_obj_to_sample停下时，行进距离与两点直线距离不相等，则认为光线无法照到这个区域
  float epsilon_dist = inter_dir.distance - (lightPositon - inter.coords).norm();
  if (epsilon_dist > -EPSILON)
  {
    // 计算从光源出发到我们眼睛的这一束光反射过来的颜色（光源->交点，交点->反射）

    float sample_emit_costheta = -dir_obj_to_sample.dot(emissionSample.normal);                           // 采样光源在theta方向上释放的能量
    float decay_dir_dist_2 = (lightPositon - inter.coords).norm() * (lightPositon - inter.coords).norm(); // 距离衰减
    float decay_dir_sum = sample_emit_costheta / decay_dir_dist_2 / emissionSamplePdf;                    // 采样光源传播总损耗
    // FIXME 为什么是 除emissionSamplePdf？

    l_dir = decay_dir_sum * (lightIntensity.cwiseProduct(inter.m->EnergyEval(ray.direction, inter.normal, dir_obj_to_sample)));
  }

  /**
   * ----------------------------------------------------------------------------------------------------------------
   * ------------------------------------- 间接光照（光源是否能够间接照射到物体）-------------------------------------------
   * ----------------------------------------------------------------------------------------------------------------
   */

  // 使用概率的方法使蒙特卡洛方法的递归迭代收敛，最终结果满足数学期望
  if (get_random_float() > XI)
  {
    return l_dir;
  }

  // EyeRay产生随机方向的反射光线，并且获取相交事件
  Vector3f dir_random_reflect = inter.m->GetRandomReflect(ray.direction, inter.normal);
  Ray ray_random_reflect(inter.coords, dir_random_reflect);
  Intersection inter_indir = GetIntersection(ray_random_reflect);

  // 如果反射光线的并未与场景中的物体发生相交，或者相交的是光源，返回直接光照
  if (inter_indir.IsHappend && !inter_indir.m->HasEmission())
  {
    // BRDF入射概率
    float reflectPdf = inter.m->GetBrdfSample(ray.direction, inter.normal, dir_random_reflect);

    //当pdf过于接近0时，会产生除0问题，造成数值过大，产生白色噪点，
    if (reflectPdf > EPSILON)
    {
      float decay_indir_sum = 1 / reflectPdf / XI; // 间接光照传播总损耗

      // 在第一碰撞点产生的反射会有能量损耗
      l_indir = decay_indir_sum * CastRay(ray_random_reflect).cwiseProduct(inter.m->EnergyEval(ray.direction, inter.normal, dir_random_reflect));
      // printf("[%f,%f,%f];\n", l_indir.x(), l_indir.y(), l_indir.z());
    }
  }

  return l_dir + l_indir;
}
