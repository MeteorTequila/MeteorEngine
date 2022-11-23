#pragma once
#ifndef METEOR_MATERIAL_H
#define METEOR_MATERIAL_H

#include "Physics.hpp"
#include "eigen-3.4.0/Eigen/Eigen"
#include "global.hpp"
#include "Shader.hpp"

using namespace Eigen;
using namespace Shader;
using namespace Shader::GeometryShader;
using namespace Shader::NormalDistributionShader;

enum MaterialType
{
  DIFFUSAL,    //漫反射
  MIRROR,      //镜面
  TRANSPARENT, //透明
  TRANSLUCENT, //半透明
  MICROFACET,

  GYPSUM,    //石膏
  GLASS,     //玻璃
  CRYSTAL,   //水晶
  VISCOUS,   //粘稠的
  IRREGULAR, //不规则的

  METAL,         //金属
  DIELECTRIC,    //电介质（绝缘体）
  SEMICONDUCTOR, //半导体
};

// 材料的折射率（IoR），介质的折射率是永远大于1的常数，如空气n=1.0003
// https://wenku.baidu.com/view/66aa6aed41323968011ca300a6c30c225801f068.html?_wkts_=1667699285779&bdQuery=%E6%9D%90%E6%96%99%E7%9A%84%E5%85%89%E5%AD%A6%E5%8F%82%E6%95%B0
// http://www.doc88.com/p-11373032301927.html

class Material
{

public:
  float IOR;            //折射率(Index Of Refraction)=c/v(其中 c 为真空下的光速，v
                        //为光在该介质中的传播速度，该折射率也称为绝对折射率)
  float reflectivity;   //反射率
  float transmissivity; //透射率
  float absorptivity;   //吸收率

  Vector3f kd; //漫反射率（对每个rgb颜色的漫反射率）
  Vector3f ks; //镜面反射率（对每个rgb色的镜面反射率）

  int exp;           //镜面指数
  MaterialType mt;   //材质类型
  Vector3f emission; //材质自发光

  // 微表面属性
  Vector3f baseColor;     //在100%强度直射下，呈现的颜色
  Vector3f specularColor; //在100%强度直射下，高光颜色
  bool subsurface;        //次表面
  float metallic;         //金属度
  float alpha_phong;      //光泽度
  float roughness;        //粗糙度
  float anisotropic;      //各向异性程度。用于控制镜面反射高光的纵横比

  Material();
  Material(MaterialType _mt);

  bool HasEmission() const;
  Vector3f GetEmission() const;
  Vector3f GetRandomReflect(const Vector3f &wi, const Vector3f &N);

  // Micorfacet 方法
  float DistributionOfNormal(const Vector3f &N, const Vector3f &h);
  float GeometryShadow(const Vector3f &l, const Vector3f &N, const Vector3f &v);

  float Lambert(const Vector3f &wi, const Vector3f &N);
  std::vector<Vector3f> Phong(const Vector3f &wi, const Vector3f &N);
  std::vector<Vector3f> BlingPhong(const Vector3f &wi, const Vector3f &N, const Vector3f &v);
  float CookTorranceSpecular(const Vector3f &wi, const Vector3f &N, const Vector3f &eye);

  float GetBrdfSample(const Vector3f &toEye, const Vector3f &N, const Vector3f &toLight);
  float GetBrdfSample_2();

  Vector3f EnergyEval(const Vector3f &wi, const Vector3f &N, const Vector3f &wo);
  Vector3f PhysicalEval(const Vector3f &wi, const Vector3f &N, const Vector3f &wo);
};

#endif