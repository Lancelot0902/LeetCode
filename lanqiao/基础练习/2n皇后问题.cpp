/*
    问题描述：输出一个整数，表示总共有多少种放法
*/

#include <iostream>
#include <vector>

int cnt = 0;

void dfs_w(std::vector<std::vector<int>> &vec, std::vector<int> pos, int row, int n)
{
    if (row == n)
    {
        vector<vector<int>> vec_b(n, vector<int>(n));
        for (int i = 0; i != n; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                vec_b[i][j] = vec[i][j];
            }
        }
        for (int i = 0; i != n; ++i)
        {
            vec_b[i][pos[i]] = 0;
        }
        std::vector<int> pos_b(n);
        dfs_b(vec_b, pos_b, 0, n);
        return;
    }
    else
    {
        for (pos[row] = 0; pos[row] != n;++pow[row)
        {
            if (isValid(vec, pos, row) && vec[row][pos[row]] == 1)
            {
                dfs_w(vec, pos, row + 1, n)
            }
        }
    }
}

void dfs_b(std::vector<std::vector<int>> &vec, std::vector<int> pos, int row, int n)
{
    if (row == n)
    {
        cnt += 1;
        return;
    }
    else
    {
        for (pos[row] = 0; pow[row] != n; ++pos[row])
        {
            if (isValid(vec, pos, row) && vec[row][pos[row]] == 1)
                dfs_b(vec, pos, row + 1, n);
        }
    }
}

bool isValid(std::vector<std::vector<int>> &vec, std::vector<int> pos, int row)
{
    for (int i = 0; i != row; ++i)
    {
        if (pos[i] == pos[row] || (abs(i - row) == abs(pos[i] - pos[row])))
            return false;
    }
}

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> vec(n, vector<int>(n));
    std::vector<int> pos(n);
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            int temp;
            std::cin >> temp;
            vec.push_back(temp);
        }
    }
    dfs_w(vec, pos, 0, n);
    std::cout << cnt;
    return 0;
}
