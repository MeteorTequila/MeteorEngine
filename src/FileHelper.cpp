#include "FileHelper.hpp"


/**
 * @brief 用于限制v的值出于区间[lo,hi]之间
 *
 * @param lo 下界
 * @param hi 上界
 * @param v 值
 * @return float
 */
float FileHelper::clamp(const float &lo, const float &hi, const float &v)
{
    return std::max(lo, std::min(hi, v));
}

/**
 * @brief 使用framebuffer生成ppm文件，像素大小为scene.width*scene.height
 *
 * @param scene 场景
 * @param framebuffer 像素容器
 */
void FileHelper::PPMGenerator(const Scene &scene, const std::vector<Vector3f> &framebuffer)
{

    printf(" - 开始导出文件\n\n");

    FILE *fp = fopen("binary.ppm", "wb");
    (void)fprintf(fp, "P6\n%d %d\n255\n", scene.width, scene.height);

    //将颜色填充到每个像素中去
    for (auto i = 0; i < scene.height * scene.width; ++i)
    {
        static unsigned char color[3];
        color[0] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].x()), 0.6f));
        color[1] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].y()), 0.6f));
        color[2] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].z()), 0.6f));
        fwrite(color, 1, 3, fp);
    }
    fclose(fp);

    // printf(" - 导出文件成功, 导出路径为 %c \n",);
}

// TODO Object文件载入方法待完善
bool FileHelper::ObjLoader(std::string &Path)
{
    // 如果不是obj文件，则失败
    if (Path.substr(Path.size() - 4, 4) != ".obj")
    {
        return false;
    }
    std::ifstream file(Path);

    // 如果文件没有打开，那么模型导入失败
    if (!file.is_open())
    {
        return false;
    }

    std::vector<Vector3f> positions;
    std::vector<Vector2f> textCoords;
    std::vector<Vector3f> normals;

    std::vector<Vertex> vertexs;
    std::vector<unsigned int> indexes;
    std::vector<std::string> meshMatNames;

    return false;
}