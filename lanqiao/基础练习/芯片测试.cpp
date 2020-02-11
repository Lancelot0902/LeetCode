/*
    问题描述：有n（2≤n≤20）块芯片，有好有坏，已知好芯片比坏芯片多。
每个芯片都能用来测试其他芯片。用好芯片测试其他芯片时，能正确给出被测试芯片是好还是坏。而用坏芯片测试其他芯片时，会随机给出好或是坏的测试结果（即此结果与被测试芯片实际的好坏无关）。
给出所有芯片的测试结果，问哪些芯片是好芯片
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> vec;
    vec.resize(n);
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
        {
            int temp;
            std::cin >> temp;
            vec[i].push_back(temp);
        }
    }
    for (int j = 0; j != n; ++j)
    {
        int temp = 0;
        for (int i = 0; i != n; ++i)
        {
            if (i != j)
                temp += vec[i][j];
        }
        if (temp >= n / 2)
            std::cout << j + 1 << " ";
    }
    return 0;
}
