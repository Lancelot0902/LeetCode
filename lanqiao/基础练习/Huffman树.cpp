/*
    问题描述：给定一列数，输出使用这列数构造Huffman树的总费用
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
    std::sort(vec.begin(), vec.end());
    int res = 0;
    while (vec.size() != 1)
    {
        int sum = vec[0] + vec[1];
        res += sum;
        vec.erase(vec.begin());
        vec.erase(vec.begin());
        vec.push_back(sum);
        std::sort(vec.begin(), vec.end());
    }
    std::cout << res;
    return 0;
}
