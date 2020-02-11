/*
    问题描述：回形取数
*/

#include <iostream>

int main(int argc, char **argv)
{
    int m, n;
    std::cin >> m >> n;
    int a[m][n];
    for (int i = 0; i != m; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            int b;
            std::cin >> b;
            a[i][j] = b;
        }
    }
    int sum = m * n;
    int i = -1;
    int j = 0;
    while (sum)
    {
        while (a[++i][j] != -1 && i != m)
        {
            std::cout << a[i][j] << " ";
            a[i][j] = -1;
            sum -= 1;
        }
        i--;
        while (a[i][++j] != -1 && j != n)
        {
            std::cout << a[i][j] << " ";
            a[i][j] = -1;
            sum -= 1;
        }
        j--;
        while (a[--i][j] != -1 && i >= 0)
        {
            std::cout << a[i][j] << " ";
            a[i][j] = -1;
            sum -= 1;
        }
        i++;
        while (a[i][--j] != -1 && j >= 0)
        {
            std::cout << a[i][j] << " ";
            a[i][j] = -1;
            sum -= 1;
        }
        j++;
    }
    return 0;
}
