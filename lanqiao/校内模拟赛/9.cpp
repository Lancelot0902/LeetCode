/*
    小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
　　请告诉小明，k 个月后空地上哪些地方有草。
 */

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int n, m, k;
    std::cin >> n >> m;
    std::vector<std::vector<char>> nums(n);
    std::vector<std::vector<int>> grassed;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
        {
            char temp;
            std::cin >> temp;
            if (temp == 'g')
                grassed.push_back({i, j});
            nums[i].push_back(temp);
        }
    }
    std::cin >> k;
    int begin = 0;
    for (int i = 0; i != k; ++i)
    {
        int size = grassed.size();
        for (int j = begin; j != size; ++j)
        {
            int a, b;
            if (grassed[j][0] - 1 >= 0)
            {
                a = grassed[j][0] - 1;
                b = grassed[j][1];
                nums[a][b] = 'g';
                grassed.push_back({a, b});
            }
            if (grassed[j][0] + 1 < n)
            {
                a = grassed[j][0] + 1;
                b = grassed[j][1];
                nums[a][b] = 'g';
                grassed.push_back({a, b});
            }
            if (grassed[j][1] - 1 >= 0)
            {
                a = grassed[j][0];
                b = grassed[j][1] - 1;
                nums[a][b] = 'g';
                grassed.push_back({a, b});
            }
            if (grassed[j][1] + 1 < m)
            {
                a = grassed[j][0];
                b = grassed[j][1] + 1;
                nums[a][b] = 'g';
                grassed.push_back({a, b});
            }
        }
        begin = size;
    }
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
            std::cout << nums[i][j];
        std::cout << std::endl;
    }
    return 0;
}
