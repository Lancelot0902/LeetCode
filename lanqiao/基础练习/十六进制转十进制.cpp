/*
    问题描述：十六进制转十进制
*/

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    std::cin >> str;
    long long ans = 0;
    for (int i = 0; i != str.size(); ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'F')
        {
            ans = ans * 16 + (str[i] - 'A' + 10);
        }
        else
        {
            ans = ans * 16 + (str[i] - '0');
        }
    }
    std::cout << ans;
    return 0;
}
