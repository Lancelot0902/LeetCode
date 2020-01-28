/*
    问题描述：编程求所有四位十进制的回文数
*/

#include <iostream>

int main(int argc,char** argv)
{
    for (int i = 1; i <= 9;++i)
    {
        for (int j = 0; j <= 9;++j)
        {
            for (int k = 0; k <= 9;++k)
            {
                for (int l = 0; l <= 9;++l)
                {
                    if(i == l && j == k)
                    {
                        std::cout << i * 1000 + j * 100 + k * 10 + l << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
