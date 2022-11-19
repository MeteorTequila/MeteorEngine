

#ifndef METEOR_FILEHELPER_H
#define METEOR_FILEHELPER_H

#include <fstream>
#include "Scene.hpp"
#include "Triangle.hpp"

class FileHelper
{
private:
    float clamp(const float &lo, const float &hi, const float &v);

public:
    void PPMGenerator(const Scene &scene, const std::vector<Vector3f> &framebuffer);
    bool ObjLoader(std::string &Path);
};



#endif