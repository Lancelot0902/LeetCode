/*
    问题描述：给定一个以秒为单位的时间t，要求用“<H>:<M>:<S>”的格式来表示这个时间
*/

#include <iostream>

int main(int argc, char **argv)
{
    int t;
    int h = 0;
    int m = 0;
    int s = 0;
    std::cin >> t;
    while (t != 0)
    {
        if (t >= 3600)
        {
            h += 1;
            t -= 3600;
            continue;
        }
        else if (t >= 60)
        {
            m += 1;
            t -= 60;
            continue;
        }
        else
        {
            s += t;
            t = 0;
        }
    }
    std::cout << h << ":" << m << ":" << s;
    return 0;
}
