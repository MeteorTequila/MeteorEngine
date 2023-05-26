#include "Material.hpp"
#include "Mesh.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "global.hpp"

int main(int argc, char *argv[])
{
  // Scene scene(1366, 768);
  Scene scene(1024, 1024);

  // Scene scene(784, 784);

  // 镜面材质
  Material *pureMirror = new Material(MIRROR);

  // 漫反射材质
  Material *white = new Material(DIFFUSAL);
  white->baseColor = {0.725f, 0.71f, 0.68f};

  Material *red = new Material(DIFFUSAL);
  red->baseColor = {0.63f, 0.065f, 0.05f};

  Material *green = new Material(DIFFUSAL);
  green->baseColor = {0.14f, 0.45f, 0.091f};

  // 微表面材质
  Material *microSurface = new Material(MICROFACET);

  // 新增光源材质
  Material *light = new Material();

  // FIXME 为啥不能把光源设置为{1,1,1}?
  // light->emission = LAMBDA * Vector3f(1.f, 1.f, 1.f);
  // light->emission = LAMBDA * Vector3f(0.6f, 0.2f, 0.8f);
  light->emission = 8.0f * Vector3f(0.747f + 0.058f, 0.747f + 0.258f, 0.747f) + 15.6f * Vector3f(0.740f + 0.287f, 0.740f + 0.160f, 0.740f) + 18.4f * Vector3f(0.737f + 0.642f, 0.737f + 0.159f, 0.737f);

  printf(" - 构造Mesh对象\n\n");
  MeshTriangle light_("../res/models/cornellbox/light.obj", light);
  MeshTriangle floor_("../res/models/cornellbox/floor.obj", white);
  MeshTriangle left_("../res/models/cornellbox/left.obj", red);
  MeshTriangle right_("../res/models/cornellbox/right.obj", green);

  MeshTriangle tallbox_("../res/models/cornellbox/tallbox.obj", microSurface);
  MeshTriangle shortbox_("../res/models/cornellbox/shortbox.obj", microSurface);

  // x y z(左手系，原点在右下角)
  Sphere sphere1(Vector3f(400, 75, 100), 75, pureMirror);

  // Vector3f cameraPos={78, 273, -800};
  // float cameraFov=40;
  // scene->eye->SetCamera(cameraPos, cameraFov);
  scene.eye.SetCamera(Vector3f(278, 273, -800), 40);

  scene.add(&light_);
  scene.add(&floor_);
  scene.add(&left_);
  scene.add(&right_);

  scene.add(&tallbox_);
  scene.add(&shortbox_);
  scene.add(&sphere1);

  printf(" - 添加物体成功，当前场景内物体数量为%lu \n\n", scene.objects.size());

  scene.PreProcessing();

  Renderer r(64);

  // FIXME 无法正确渲染镜面，原因未知(根据观察，越垂直于视线方向的平面越黑，推测可能evalEnergy计算夹角出了问题)
  // r.PathTracer_0(scene);
  r.PathTracer_2(scene);

  printf("t0 is %d, t1 is %d, t2 is %d ,t3 is %d ,t4 is %d\n\n", arg_t0, arg_t1, arg_t2, arg_t3, arg_t4);
}