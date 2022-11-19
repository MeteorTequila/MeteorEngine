#include <math.h>
#include "eigen-3.4.0/Eigen/Eigen"

using namespace Eigen;

// 当x<0时，sign(x)=-1；
// 当x=0时，sign(x)=0; 当x>0时，sign(x)=1。
int sign(float x)
{
    if (x < 0)
        return -1;
    else if (x == 0)
        return 0;
    else
        return 1;
}

// %  Generate X Y Z coordinates of a 3D Bresenham's line between
// %  two given points.
// %
// %  A very useful application of this algorithm can be found in the
// %  implementation of Fischer's Bresenham interpolation method in my
// %  another program that can rotate three dimensional image volume
// %  with an affine matrix:
// %  http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=21080
// %
// %  Usage: [X Y Z] = bresenham_line3d(begin, end, [precision]);
// %
// %  begin	- vector for Point1, where begin = [x1 y1 z1]
// %
// %  end	- vector for Point2, where end = [x2 y2 z2]
// %
// %  precision (optional) - Although according to Bresenham's line
// %	algorithm, point coordinates x1 y1 z1 and x2 y2 z2 should
// %	be integer numbers, this program extends its limit to all
// %	real numbers. If any of them are floating numbers, you
// %	should specify how many digits of decimal that you would
// %	like to preserve. Be aware that the length of output X Y
// %	Z coordinates will increase in 10 times for each decimal
// %	digit that you want to preserve. By default, the precision
// %	is 0, which means that they will be rounded to the nearest
// %	integer.
// %
// %  X	- a set of x coordinates on Bresenham's line
// %
// %  Y	- a set of y coordinates on Bresenham's line
// %
// %  Z	- a set of z coordinates on Bresenham's line
// %
// %  Therefore, all points in XYZ set (i.e. P(i) = [X(i) Y(i) Z(i)])
// %  will constitute the Bresenham's line between begin and begin.
// %
// %  Example:
// %	begin = [12 37 6];     end = [46 3 35];
// %	[X Y Z] = bresenham_line3d(begin, end);
// %	figure; plot3(X,Y,Z,'s','markerface','b');
// %
// %  This program is ported to MATLAB from:
// %
// %  B.Pendleton.  line3d - 3D Bresenham's (a 3D line drawing algorithm)
// %  ftp://ftp.isc.org/pub/usenet/comp.sources.unix/volume26/line3d, 1992
// %
// %  Which is also referenced by:
// %
// %  Fischer, J., A. del Rio (2004).  A Fast Method for Applying Rigid
// %  Transformations to Volume Data, WSCG2004 Conference.
// %  http://wscg.zcu.cz/wscg2004/Papers_2004_Short/M19.pdf
// %
// %  - Jimmy Shen (jimmy@rotman-baycrest.on.ca)
// %
Vector3f BresenhamLine3D(Vector3f begin, Vector3f end, float precision)
{

    precision = std::round(precision);
    if (precision == 0)
    {
        begin.x() = std::round(begin.x());
        begin.y() = std::round(begin.y());
        begin.z() = std::round(begin.z());

        end.x() = std::round(end.x());
        end.y() = std::round(end.y());
        end.z() = std::round(end.z());
    }
    else
    {
        float t = std::pow(10, precision);
        begin.x() = std::round(begin.x() * t);
        begin.y() = std::round(begin.y() * t);
        begin.z() = std::round(begin.z() * t);

        end.x() = std::round(end.x() * t);
        end.y() = std::round(end.y() * t);
        end.z() = std::round(end.z() * t);
    }

    //向量end-begin中的元素的绝对值的最大项，(无穷范数+1)
    // float d = std::max(std::abs(end - begin) + 1);
    auto d = (end - begin).lpNorm<Infinity>() + 1;
    // temp.maxCoeff();
    VectorXf X = VectorXf::Zero(d);
    VectorXf Y = VectorXf::Zero(d);
    VectorXf Z = VectorXf::Zero(d);

    Vector3f p1 = begin;
    Vector3f p2 = end;

    float dx = p2.x() - p1.x();
    float dy = p2.y() - p1.y();
    float dz = p2.z() - p1.z();

    float ax = std::abs(dx) * 2;
    float ay = std::abs(dy) * 2;
    float az = std::abs(dz) * 2;

    int sx = sign(dx);
    int sy = sign(dy);
    int sz = sign(dz);

    Vector3f p = p1;
    int index = 1;

    if (ax >= std::max(ay, az))
    {
        float yd = ay - ax / 2;
        float zd = az - ax / 2;

        while (1)
        {
            X(index) = p.x();
            Y(index) = p.y();
            Z(index) = p.z();
            index = index + 1;

            if (p.x() == end.x())
            {
                break;
            }

            if (yd >= 0)
            {
                p.y() += sy;
                yd = yd - ax;
            }

            if (zd >= 0)
            {
                p.z() += sz;
                zd = zd - ax;
            }

            p.x() = p.x() + sx;
            yd = yd + ay;
            zd = zd + az;
        }
    }
    else if (ay >= std::max(ax, az))
    {
        float xd = ax - ay / 2;
        float zd = az - ay / 2;

        while (1)
        {
            X(index) = p.x();
            Y(index) = p.y();
            Z(index) = p.z();
            index = index + 1;

            if (p.y() == end.y())
            {
                break;
            }

            if (xd >= 0)
            {

                p.x() += sx;
                xd = xd - ay;
            }

            if (zd >= 0)
            {

                p.z() += sz;
                zd = zd - ay;
            }

            p.y() += sy;
            xd = xd + ax;
            zd = zd + az;
        }
    }
    else if (az >= std::max(ax, ay))
    {

        float xd = ax - az / 2;
        float yd = ay - az / 2;

        while (1)
        {
            X(index) = p.x();
            Y(index) = p.y();
            Z(index) = p.z();
            index = index + 1;

            if (p.z() == end.z())
            {
                break;
            }

            if (xd >= 0)
            {
                p.x() += sx;
                xd = xd - az;
            }

            if (yd >= 0)
            {
                p.y() += sy;
                yd = yd - az;
            }

            p.z() += sz;
            xd = xd + ax;
            yd = yd + ay;
        }
    }

    if (precision != 0)
    {

        X = X / std::pow(10, precision);
        Y = Y / std::pow(10, precision);
        Z = Z / std::pow(10, precision);
        // % bresenham_line3d
    }
}

// Bresenham's line drawing algorithm
// Code taken from a stack overflow answer: https://stackoverflow.com/a/16405254
void BresenhamLine2D(Vector3f begin, Vector3f end)
{
    auto x1 = begin.x();
    auto y1 = begin.y();
    auto x2 = end.x();
    auto y2 = end.y();

    Vector3f line_color = {255, 255, 255};

    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;

    dx = x2 - x1;
    dy = y2 - y1;
    dx1 = fabs(dx);
    dy1 = fabs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;

    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x = x1;
            y = y1;
            xe = x2;
        }
        else
        {
            x = x2;
            y = y2;
            xe = x1;
        }
        Vector3f point = Vector3f(x, y, 1.0f);
        // set_pixel(point, line_color);
        for (i = 0; x < xe; i++)
        {
            x = x + 1;
            if (px < 0)
            {
                px = px + 2 * dy1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    y = y + 1;
                }
                else
                {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            //            delay(0);
            Vector3f point = Vector3f(x, y, 1.0f);
            // set_pixel(point, line_color);
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = x1;
            y = y1;
            ye = y2;
        }
        else
        {
            x = x2;
            y = y2;
            ye = y1;
        }
        Vector3f point = Vector3f(x, y, 1.0f);
        // set_pixel(point, line_color);
        for (i = 0; y < ye; i++)
        {
            y = y + 1;
            if (py <= 0)
            {
                py = py + 2 * dx1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    x = x + 1;
                }
                else
                {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            //            delay(0);
            Vector3f point = Vector3f(x, y, 1.0f);
            // set_pixel(point, line_color);
        }
    }
}