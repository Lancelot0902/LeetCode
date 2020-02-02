/*
    问题描述：矩阵乘法
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int a;
    int b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> vec;
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> index;
    vec.resize(a);
    res.resize(a);
    index.resize(a);
    for (int i = 0; i != a; ++i)
    {
        for (int j = 0; j != a; ++j)
        {
            int temp;
            std::cin >> temp;
            vec[i].push_back(temp);
            res[i].push_back(temp);
            index[i].push_back(temp);
        }
    }
    if (b == 0)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i != j)
                {
                    std::cout << 0 << " ";
                }
                else
                {
                    std::cout << 1 << " ";
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }
    for (int k = 1; k != b; ++k)
    {
        for (int i = 0; i != a; ++i)
        {
            for (int j = 0; j != a; ++j)
            {
                int temp = 0;
                for (int m = 0; m != a; ++m)
                {
                    temp += res[i][m] * vec[m][j];
                }
                index[i][j] = temp;
            }
        }
        for (int i = 0; i != a; ++i)
        {
            for (int j = 0; j != a; ++j)
            {
                res[i][j] = index[i][j];
            }
        }
    }
    for (int i = 0; i != a; ++i)
    {
        for (int j = 0; j != a; ++j)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
