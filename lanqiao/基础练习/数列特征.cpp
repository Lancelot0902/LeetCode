/*
    问题描述：给一个数列，列举出这个数列的最大值、最小值、和
*/

#include <iostream>
#include <vector>

int main(int argc,char** argv)
{
    std::vector<int> vec;
    int n;
    std::cin >> n;
    int min = 0;
    int max = 0;
    int sum = 0;
    for (int i = 0; i != n;++i)
    {
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    min = vec[0];
    max = vec[0];
    sum = vec[0];
    for (int i = 1; i != n;++i)
    {
        if(vec[i] > max)
            max = vec[i];
        if(vec[i] < min)
            min = vec[i];
        sum += vec[i];
    }
    std::cout << max << std::endl;
    std::cout << min << std::endl;
    std::cout << sum;
    return 0;
}
