/*
    问题描述：输出杨辉三角
*/

#include <iostream>
#include <vector>

int main(int argc,char** argv)
{
    std::vector<std::vector<int>> vec;
    int n;
    std::cin >> n;
    vec.resize(n);
    for (int i = 0; i != n;++i)
    {
        vec[i].push_back(1);
        for (int j = 1; j < i;++j)
        {
            vec[i].push_back(vec[i - 1][j - 1] + vec[i - 1][j]);
        }
        vec[i].push_back(1);
    }
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
