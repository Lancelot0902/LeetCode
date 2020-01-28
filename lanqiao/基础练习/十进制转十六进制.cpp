/*
    问题描述：十进制转十六进制
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<char> vec;
    int num;
    std::cin >> num;
    if (num == 0)
        std::cout << "0" << std::endl;
    else
    {
        while (num != 0)
        {
            if (num % 16 >= 10)
                vec.push_back(num % 16 - 10 + 'A');
            else
                vec.push_back(num % 16 + '0');
            num /= 16;
        }
    }
    for (int i = vec.size() - 1; i >= 0; --i)
        std::cout << vec[i];
    return 0;
}
