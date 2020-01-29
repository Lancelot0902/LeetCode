/*
    问题描述：输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n
*/

#include <iostream>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    for (int a = 1; a <= 9; ++a)
        for (int b = 0; b <= 9; ++b)
            for (int c = 0; c <= 9; ++c)
            {
                if ((a + b + c + b + a) == n)
                    std::cout << a << b << c << b << a << std::endl;
            }

    for (int a = 1; a <= 9; ++a)
        for (int b = 0; b <= 9; ++b)
            for (int c = 0; c <= 9; ++c)
            {
                if ((a + b + c + c + b + a) == n)
                    std::cout << a << b << c << c << b << a << std::endl;
            }
    return 0;
}
