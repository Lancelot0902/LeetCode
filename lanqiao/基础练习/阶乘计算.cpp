/*
    问题描述：输出n!的准确值
*/

#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::string res = "1";
    int m = 1;
    while (m <= n)
    {
        int r = 0;
        for (int i = 0; i != res.size(); ++i)
        {
            int a = res[i] - '0';
            int temp = a * m + r;
            res[i] = temp % 10 + '0';
            r = temp / 10;
        }
        while (r)
        {
            res += r % 10 + '0';
            r /= 10;
        }
        m += 1;
    }
    std::reverse(res.begin(), res.end());
    std::cout << res;
    return 0;
}
