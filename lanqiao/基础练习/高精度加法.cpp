/*
    问题描述：输出a+b
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string a;
    std::string b;
    int r = 0;
    std::cin >> a >> b;
    if (a.size() < b.size())
        std::swap(a, b);
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0)
    {
        int x = a[i] - '0';
        int y = 0;
        if (j >= 0)
        {
            y = b[j--] - '0';
        }
        if (x + y + r >= 10)
        {
            a[i--] = x + y + r - 10 + '0';
            r = 1;
        }
        else
        {
            a[i--] = x + y + r + '0';
            r = 0;
        }
    }
    if (r == 1)
        a = '1' + a;
    std::cout << a;
    return 0;
}
