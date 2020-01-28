/*
    问题描述：输出一个n行m列的图形
*/

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i != n;++i)
    {
        for (int j = 0; j != m;++j)
        {
            std::cout << char('A' + abs(i - j));
        }
        std::cout << std::endl;
    }
    return 0;
}
