/*
    问题描述：当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
*/

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<int> vec;
    vec.resize(1000001);
    vec[1] = vec[2] = 1;
    int n;
    std::cin >> n;
    for (int i = 3; i <= 1000000; ++i)
    {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 10007;
    }
    std::cout << vec[n];
    return 0;
}