/*
    问题描述：输入包含一个整数n，求1+2+3+...+n的值
*/

#include <iostream>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    long long sum = 0;
    sum = (1 + n) * n / 2;
    std::cout << sum;
    return 0;
}