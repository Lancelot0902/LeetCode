/*
    问题描述：交换一个字符串使之变成回文串，输出最少交换的次数
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int n;
    std::string str;
    std::cin >> n;
    std::cin >> str;

    int end = n - 1;
    int res = 0;
    int mid = 0;

    for (int i = 0; i < end; ++i)
    {
        for (int j = end; j >= i; --j)
        {
            if (i == j)
            {
                if (mid == 1 || n % 2 == 0)
                {
                    std::cout << "Impossible";
                    return 0;
                }
                mid = 1;
                res += n / 2 - i;
            }
            else if (str[i] == str[j])
            {
                for (int k = j; k < end; ++k)
                {
                    std::swap(str[k], str[k + 1]);
                    res += 1;
                }
                end -= 1;
                break;
            }
        }
    }
    std::cout << res;
    return 0;
}
