#include "Renderer.hpp"
#include "FileHelper.hpp"
#include <thread>
#include <mutex>
#include <omp.h>

//定义线程互斥锁
std::mutex mutex_ins;

// 构造函数
// Renderer::Renderer(Scene *_scene)
// {
//     scene = _scene;
// }

// 角度转弧度
float Deg2Rad(float degree) { return degree * M_PI / 180; }

//视角变换矩阵
Matrix4f Renderer::GetProjectionMatrix(Scene &scene)
{
  /*
   * 视图变换
   * 模型变换（modeling
   * tranformation）：将一个物体自身进行变换（缩放、旋转、位移） 视角变换（view
   * tranformation）：根据眼睛来判断物体的相对位置 投影变换（projection
   * tranformation）：将三维空间内的物体投影至标准二维平面([-1,1]^2)之上
   * 视口变换（viewport
   * transformation）：将处于标准平面映射到屏幕分辨率范围之内，即[-1,1]^2→\rightarrow→[0,width]*[0,height],
   * 其中width和height指屏幕分辨率大小
   */

  //获取摄像机参数

  Vector3f eyePos = scene.eye.pos;           //获取摄像机坐标
  float eyeFov = Deg2Rad(scene.eye.fov);     //视野广度
  float aspectRatio = scene.eye.aspectRatio; //屏幕高宽比
  float zNear = 1;
  float zFar = 50;

  //定义变换矩阵
  Matrix4f scaleMatrix = Matrix4f::Identity();      //缩放
  Matrix4f transMatrix = Matrix4f::Identity();      //平移
  Matrix4f orthoMatrix = Matrix4f::Identity();      //正交变换
  Matrix4f projectionMatrix = Matrix4f::Identity(); //投影

  //根据摄像机的参数，布局一个“成像平面”
  float top = 1 * tan(0.5 * eyeFov);
  float bottom = -top;
  float right = top * aspectRatio;
  float left = -right;

  //将原有的图形，缩放为一个2*2*2的立方体
  scaleMatrix << (2 - 0) / (right - left), 0, 0, 0, 0, (2 - 0) / (top - bottom),
      0, 0, 0, 0, 0, (2 - 0) / (zNear - zFar), 0, 0, 0, 1;

  //平移2*2*2的立方体，将其中心放置在原点
  transMatrix << 1, 0, 0, -(right + left) / 2, 0, 1, 0, -(top + bottom) / 2, 0,
      0, 1, -(zNear + zFar) / 2, 0, 0, 0, 1;

  //执行上面2步，得到正交变换矩阵
  orthoMatrix = scaleMatrix * transMatrix;

  //将正交投影变换为透视投影
  Matrix4f ortho2ProjMatrix;
  ortho2ProjMatrix << zNear, 0, 0, 0, 0, zNear, 0, 0, 0, 0, zNear + zFar,
      -zNear * zFar, 0, 0, 1, 0;

  //执行上述变换，得到投影矩阵
  projectionMatrix = orthoMatrix * ortho2ProjMatrix;

  return projectionMatrix;
}

// 从摄像机穿过像素平面看向物体
void Renderer::PathTracer_0(Scene &scene)
{
  printf(" - 执行普通渲染\n\n");

  FileHelper fh;
  std::vector<Vector3f> tempframebuffer((scene.width) * (scene.height)); //临时变量
  float scale = tan(Deg2Rad(scene.eye.fov * 0.5));                       //缩放比例
  float imageAspectRatio = scene.width / (float)scene.height;            //图像宽高比
  Vector3f eyePos = scene.eye.pos;                                       //摄像机位置
  int m = 0;

  for (uint32_t j = 0; j < scene.height; ++j)
  {
    for (uint32_t i = 0; i < scene.width; ++i)
    {
      //  这里会创建一道 EyeRay 用来着色，可以理解为这里是Ray中着色的主线程
      //  对每个像素做MVP变化
      float x = (2 * (i + 0.5) / (float)scene.width - 1) * imageAspectRatio * scale;
      float y = (1 - 2 * (j + 0.5) / (float)scene.height) * scale;

      Vector3f dir = Vector3f(-x, y, 1).normalized();

      //遍历每个样本，用每个样本光源做一次castRay操作，对最后累加的值取平均值
      for (int k = 0; k < spp; k++)
      {
        tempframebuffer[m] += scene.CastRay(Ray(eyePos, dir)) / spp;
      }

      m++;
    }
  }
  this->framebuffer = tempframebuffer;

  fh.PPMGenerator(scene, framebuffer);
}

/**
 * @brief 最终渲染函数，在此处生成图像
 * 在中间使用蒙特卡洛方法，对每个像素发射spp道EyeRay，最后取所有EyeRay的平均值
 */
void Renderer::PathTracer_1(Scene &scene)
{
  // #pragma omp parallel for

  // TODO 需要添加进度条计数器
  printf(" - 执行多线程渲染\n\n");

  int process = 0;
  FileHelper fh;
  std::vector<Vector3f> tempframebuffer(scene.width * scene.height); //临时变量
  float scale = tan(Deg2Rad(scene.eye.fov * 0.5));                   //缩放比例
  float imageAspectRatio = scene.width / (float)scene.height;        //图像宽高比
  Vector3f eyePos = scene.eye.pos;                                   //摄像机位置

  // 创造匿名函数，功能是块内遍历，用于多线程并行执行
  auto castRayMultiThreading = [&](uint32_t rowStart, uint32_t rowEnd, uint32_t colStart, uint32_t colEnd)
  {
    for (uint32_t j = rowStart; j < rowEnd; ++j) //按照行号遍历
    {
      int m = j * scene.width + colStart;          // m表示像素在framebuffer里的index
      for (uint32_t i = colStart; i < colEnd; ++i) // 按列号遍历
      {
        // generate primary ray direction
        // 将像素做MVP逆变换
        float x = (2 * (i + 0.5) / (float)scene.width - 1) * imageAspectRatio * scale;
        float y = (1 - 2 * (j + 0.5) / (float)scene.height) * scale;

        Vector3f dir = Vector3f(-x, y, 1).normalized();

        //对每个像素的每个样本castRay
        for (int k = 0; k < spp; k++)
        {
          tempframebuffer[m] += scene.CastRay(Ray(eyePos, dir)) / spp;
        }
        m++;       //当前像素渲染完毕，自增准备渲染下一个
        process++; //进程+1，表示dang
      }

      // 互斥锁，用于打印处理进程
      //相比于mutex功能，lock_guard具有创建时加锁，析构时解锁的功能，类似于智能指针，
      //为了防止在线程使用mutex加锁后异常退出导致死锁的问题，建议使用lock_guard代替mutex
      //在作用域中自动lock，出了作用域后自动unlock
      std::lock_guard<std::mutex> g1(mutex_ins);

      //受到上面的互斥锁控制，kernel状态无法执行下面的语句
      UpdateProgress(1.0 * process / scene.width / scene.height);
    }
  };

  int id = 0; //线程id

  // constexpr表达式是指值不会改变并且在编译过程就能得到计算结果的表达式
  constexpr int bx = 8;    //为row创建5个线程块
  constexpr int by = 8;    //为column创建5个线程块
  std::thread th[bx * by]; //线程池大小

  int strideX = (scene.width + 1) / bx;  // 每个row线程块的步长
  int strideY = (scene.height + 1) / by; // 每个column线程块的步长

  // 分块创建光线追踪线程
  //创建i*j线程块，并装载线程
  for (int i = 0; i < scene.height; i += strideX)
  {
    for (int j = 0; j < scene.width; j += strideY)
    {
      //双层循环中，i的递进步长为strideX，j的递进步长为strideY
      //创建i*j个线程
      th[id] = std::thread(castRayMultiThreading, i, std::min(i + strideX, scene.height), j, std::min(j + strideY, scene.width));
      id++;
    }
  }

  //执行每个线程块
  // #pragma omp parallel for
  for (int i = 0; i < bx * by; i++)
  {
    th[i].join();
  }
  UpdateProgress(1.f);

  this->framebuffer = tempframebuffer;

  fh.PPMGenerator(scene, framebuffer);
}

int prog = 0;
std::mutex lock;

/**
 * @brief omp多线程函数
 * 在成员类中声明多线程函数会报错，解决办法是在类头文件中将方法声明为静态方法
 * https://www.jianshu.com/p/2f9b9b4645c6
 */
void Renderer::para(Vector3f _eyePos, std::vector<Vector3f> &_framebuffer, Scene &_scene, int _spp, float _imageAspectRatio, float _scale, int _start, int _end)
{
  int width, height;
  width = height = std::sqrt(_spp);
  float step = 1.0f / width;
  for (uint32_t j = _start; j < _end; ++j)
  {
    for (uint32_t i = 0; i < _scene.width; ++i)
    {
      // generate primary ray direction
      for (int k = 0; k < _spp; k++)
      {
        float x = (2 * (i + step / 2 + step * (k % width)) / (float)_scene.width - 1) * _imageAspectRatio * _scale;
        float y = (1 - 2 * (j + step / 2 + step * (k / height)) / (float)_scene.height) * _scale;
        Vector3f dir = Vector3f(-x, y, 1).normalized();
        _framebuffer[j * _scene.width + i] += _scene.CastRay(Ray(_eyePos, dir)) / _spp;
      }
    }
    // 线程锁
    lock.lock();
    prog++;
    UpdateProgress(prog / (float)_scene.height);
    lock.unlock();
  }
}

/**
 * @brief omp方法的多线程渲染
 * https://blog.csdn.net/ycrsw/article/details/124408789?spm=1001.2014.3001.5502
 * @param scene
 */
void Renderer::PathTracer_2(Scene &scene)
{
  printf(" - 执行openmp多线程渲染\n\n");

  FileHelper fh;
  std::vector<Vector3f> tempframebuffer((scene.width) * (scene.height)); //临时变量
  float scale = tan(Deg2Rad(scene.eye.fov * 0.5));                       //缩放比例
  float imageAspectRatio = scene.width / (float)scene.height;            //图像宽高比
  Vector3f eyePos = scene.eye.pos;                                       //摄像机位置

  int thread_num = 32;
  int thread_step = scene.height / thread_num;
  std::vector<std::thread> rays;
#pragma omp parallel for
  for (int i = 0; i < thread_num; ++i)
  {
    para(eyePos, std::ref(tempframebuffer), std::ref(scene), this->spp, imageAspectRatio, scale, i * thread_step, (i + 1) * thread_step);
  }

  UpdateProgress(1.f);
  this->framebuffer = tempframebuffer;

  fh.PPMGenerator(scene, framebuffer);
}