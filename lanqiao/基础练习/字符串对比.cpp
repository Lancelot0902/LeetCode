/*
    问题描述：给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关
系是以下4中情况
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string a;
    std::string b;
    std::cin >> a >> b;
    if (a.size() != b.size())
        std::cout << 1;
    else
    {
        int flag = 2;
        for (int i = 0; i != a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                if (a[i] == b[i] + 32 || a[i] == b[i] - 32)
                    flag = 3;
                else
                    flag = 4;
                break;
            }
        }
        std::cout << flag;
    }
    return 0;
}
