/*
    问题描述：给定圆的半径r，求圆的面积
*/

#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
    int r = 0;
    std::cin >> r;
    double PI = 3.14159265358979323;
    double area = r * r * PI;
    std::cout << std::fixed << std::setprecision(2) << area;
    return 0;
}