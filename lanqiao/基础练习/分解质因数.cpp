/*
    问题描述：求出区间[a,b]中所有整数的质因数分解
*/

#include <iostream>

int main(int argc, char **argv)
{
    int a;
    int b;
    std::cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        int n = i;
        bool flag = false;
        std::cout << n << "=";
        for (int j = 2; j <= n; ++j)
        {
            while (j != n)
            {
                if (n % j == 0)
                {
                    if (flag)
                        std::cout << "*";
                    std::cout << j;
                    flag = true;
                    n /= j;
                }
                else
                    break;
            }
        }
        if (flag)
            std::cout << "*";
        std::cout << n << std::endl;
    }
    return 0;
}
