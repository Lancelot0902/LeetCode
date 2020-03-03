/*
    问题描述：给定平面上n个点。求两条直线，这两条直线互相垂直，而且它们与x轴的夹角为45度，并且n个点中离这两条直线的曼哈顿距离的最大值最小。
    两点之间的曼哈顿距离定义为横坐标的差的绝对值与纵坐标的差的绝对值之和，一个点到两条直线的曼哈顿距离是指该点到两条直线上的所有点的曼哈顿距离中的最小值。
*/

#include <iostream>
#include <vector>

#define max_float 999.9

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> vec;
    std::vector<std::vector<int>> line;
    std::vector<std::vector<int>> slope;
    for (int i = 0; i != n; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        vec.push_back({x, y});
    }
    for (int i = 0; i != n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(vec[i][0] - vec[j][0]) / abs(vec[i][1] - vec[j][1]) == 1)
            {
                slope.push_back({i, j});
            }
        }
    }
    for (int i = 0; i != slope.size(); ++i)
    {
        for (int j = i + 1; j < slope.size(); ++j)
        {
            int x1 = slope[i][0];
            int y1 = slope[i][1];
            int x2 = slope[j][0];
            int y2 = slope[j][1];
            float a = (vec[x1][0] - vec[y1][0]) / (vec[x1][1] - vec[y1][1]);
            float b = (vec[x2][0] - vec[y2][0]) / (vec[x2][1] - vec[y2][1]);
            if (a * b == -1.0)
            {
                line.push_back({x1, y1, x2, y2});
            }
        }
    }
    float ans = max_float;
    for (int i = 0; i != line.size(); ++i)
    {
        float max_man = 0.0;
        for (int j = 0; j != vec.size(); ++j)
        {
            float min_man = max_float;
            for (int k = 0; k != 4; ++k)
            {
                int index = line[i][k];
                float man = abs(vec[j][0] - vec[index][0]) + abs(vec[j][1] - vec[index][1]);
                if (min_man > man)
                    min_max = min_man;
            }
            if (min_man > max_man)
                max_man = min_man;
        }
        if (max_man < ans)
            ans = max_man;
    }
    std::cout << ans;
}
