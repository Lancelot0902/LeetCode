/*
    问题描述：预测龟兔赛跑的结果
*/

#include <iostream>

int main(int argc, char **argv)
{
    int v1, v2, t, s, l;
    std::cin >> v1 >> v2 >> t >> s >> l;
    int s1 = 0;
    int s2 = 0;
    int times = 0;
    while (s1 < l && s2 < l)
    {
        if (s1 - s2 >= t)
        {
            while (s--)
            {
                s2 += v2;
                times += 1;
                if (s2 >= l)
                    break;
            }
        }
        else
        {
            s1 += v1;
            s2 += v2;
            times += 1;
        }
    }
    if (s1 == s2)
        std::cout << "D" << std::endl;
    else if (s1 > s2)
        std::cout << "R" << std::endl;
    else
        std::cout << "T" << std::endl;
    std::cout << times;
    return 0;
}
