/*
    问题描述：给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 0; i != n; ++i)
    {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    int num;
    std::cin >> num;
    int i = 0;
    for (; i != vec.size(); ++i)
    {
        if (vec[i] == num)
        {
            break;
        }
    }
    if (i == vec.size())
        std::cout << -1;
    else
        std::cout << i + 1;
    return 0;
}
