/*
    问题描述：设An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)，Sn=(...(A1+n)A2+n-1)A3+...+2)An+1，输入n，计算sn
*/

#include <iostream>
#include <string>

void an(int n)
{
    if (n == 1)
    {
        std::cout << "sin(1)";
        return;
    }
    for (int i = 1; i != n; ++i)
    {
        if (i % 2 == 0)
        {
            std::cout << "sin(" << i << "+";
        }
        else
        {
            std::cout << "sin(" << i << "-";
        }
    }
    std::cout << "sin(" << n;
    for (int i = 0; i != n; ++i)
        std::cout << ")";
}

void sn(int n)
{
    for (int i = 1; i != n; ++i)
        std::cout << "(";
    int temp = n;
    for (int i = 1; i != n; ++i)
    {
        an(i);
        std::cout << "+" << temp-- << ")";
    }
    an(n);
    std::cout << "+1";
}

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    sn(n);
    return 0;
}
