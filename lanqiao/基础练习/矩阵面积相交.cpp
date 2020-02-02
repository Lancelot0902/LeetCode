/*
    问题描述：平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们
给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

int main(int argc, char **argv)
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x1 > x2)
        std::swap(x1, x2);
    if (y1 > y2)
        std::swap(y1, y2);
    if (x3 > x4)
        std::swap(x3, x4);
    if (y3 > y4)
        std::swap(y3, y4);

    if ((x2 < x3) || (x4 < x1) || (y2 < y3) || (y4 < y1))
        std::cout << 0.00;
    else
    {
        double a[4] = {x1, x2, x3, x4};
        double b[4] = {y1, y2, y3, y4};
        std::sort(a, a + 4);
        std::sort(b, b + 4);
        double area = (a[2] - a[1]) * (b[2] - b[1]);
        std::cout << std::fixed << std::setprecision(2) << area;
    }
    return 0;
}
