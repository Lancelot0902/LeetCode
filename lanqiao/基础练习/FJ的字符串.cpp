/*
    问题描述:输入n，并输出给定an
*/

#include <iostream>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::string str = "A";
    for (int i = 1; i != n; ++i)
    {
        char temp = 'A' + i;
        str = str + temp + str;
    }
    std::cout << str;
    return 0;
}
