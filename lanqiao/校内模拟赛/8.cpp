/*
    小明想知道，满足以下条件的正整数序列的数量：
　　1. 第一项为 n；
　　2. 第二项不超过 n；
　　3. 从第三项开始，每一项小于前两项的差的绝对值。
　　请计算，对于给定的 n，有多少种满足条件的序列。
 */

#include <iostream>

int count = 0;

void dfs(int n, int i)
{
    count = (count + 1) % 10000;
    if (std::abs(n - i) < 1)
    {
        return;
    }
    for (int j = 1; j < std::abs(n - i); ++j)
    {
        dfs(i, j);
    }
}

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        dfs(n, i);
    }
    std::cout << count;
    return 0;
}
