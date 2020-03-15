/*
    在1至2019中，有多少个数的数位中包含数字9？
 */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int sum = 0;
    for (int i = 9; i <= 2019; ++i)
    {
        std::string s = std::to_string(i);
        int flag = 0;
        for (int j = 0; j != s.size(); ++j)
        {
            if (s[j] == '9')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            sum += 1;
    }
    std::cout << sum;
    return 0;
}
