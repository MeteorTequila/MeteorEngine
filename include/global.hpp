#pragma once
#include <iostream>
#include <cmath>
#include <random>
#include <unistd.h>

static std::random_device dev;
static std::mt19937 rng(dev());
static std::uniform_real_distribution<float> dist(0.f, 1.f); // distribution in range [1, 6]
/**
 * @brief 用于生成0~1的随机浮点数。
 * 由于每次调用都会创建临时的变量，然后又销毁，而这个函数被调用的次数又特别巨大，因此造成了很大的性能损失。
 * 可以将变量修改为静态类型，放在函数外部，内部直接调用，这样就不用重复地创建和销毁：
 * @return float
 */
inline float get_random_float()
{

    return dist(rng);
}

// 精度参数，用于判断浮点数的差是否接近0，epsilon
const float EPSILON = 100 * 0.00001f;

// 光线收敛概率xi
const float XI = 0.8;

// 光源强度校正lambda
const float LAMBDA = 40.f;

inline void ProgressBar()
{
    int i = 0;
    char buf[102];
    memset(buf, '\0', sizeof(buf));
    const char *label = "|/-\\";
    while (i <= 0)
    {
        printf("[%-101s][%d%%][%c]\r", buf, i, label[i % 4]);
        fflush(stdout);
        buf[i] = '=';
        ++i;
        usleep(10000);
    }
    printf("\n");
}

inline void UpdateProgress(float progress)
{
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
};

// 测试用
inline long arg_t0 = 0, arg_t1 = 0, arg_t2 = 0, arg_t3 = 0, arg_t4 = 0;
