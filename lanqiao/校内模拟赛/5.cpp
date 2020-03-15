/*
    一个正整数如果任何一个数位不大于右边相邻的数位，则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一个数位递增的数。
　　给定正整数 n，请问在整数 1 至 n 中有多少个数位递增的数？
 */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    if (n < 10)
    {
        std::cout << n;
        return 0;
    }
    int sum = 9;
    for (int i = 11; i <= n; ++i)
    {
        std::string s = std::to_string(i);
        int flag = 1;
        for (int j = 0; j != s.size() - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            sum += 1;
    }
    std::cout << sum;
    return 0;
}
