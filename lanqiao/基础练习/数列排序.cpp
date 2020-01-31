/*
    问题描述：给定一个长度为n的数列，将这个数列按从小到大的顺序排列
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<int> vec;
    for (int i = 0; i != n; ++i)
    {
        int num;
        std::cin >> num;
        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i != n; ++i)
        std::cout << vec[i] << " ";
    return 0;
}
