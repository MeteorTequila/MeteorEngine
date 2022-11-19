#pragma once

#include "Scene.hpp"

class Renderer
{

public:
    // Scene *scene;
    std::vector<Vector3f> framebuffer;
    int spp = 2; //每像素入射光线采样数量，sample per pixel

    Renderer(const int &_spp):spp(_spp) { printf(" - 开始渲染\n\n"); };
    ~Renderer() { printf(" - 渲染完毕\n\n"); }

    // 为什么使用const
    // 防止修饰的变量被修改，刚接触这一点时，还是有点懵的。都const修饰了，怎么可能被修改？
    // https://blog.csdn.net/qq_45654722/article/details/106104914
    void Render_0(Scene &scene);
    void Render_1(Scene &scene);
    void Render_2(Scene &scene);

    Matrix4f GetProjectionMatrix(Scene &scene);

private:
    static void para(Vector3f eyePos, std::vector<Vector3f> &framebuffer, Scene &scene, int spp, float imageAspectRatio, float scale, int start, int end);
};