/*
    问题描述：对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能，请按从小到大的顺序输出这32种01串
*/

#include <iostream>
#include <string>

std::string plusOne(std::string str)
{
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == '0')
        {
            str[i] = '1';
            break;
        }
        if (str[i] == '1')
        {
            str[i] = '0';
        }
    }
    return str;
}

int main(int argc, char **argv)
{
    std::string str = "00000";
    for (int i = 0; i != 32; ++i)
    {
        std::cout << str << std::endl;
        str = plusOne(str);
    }
    return 0;
}