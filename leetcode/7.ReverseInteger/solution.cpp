#include <iostream>
#include <vector>

int reverse(int x)
{
    std::vector<int> vec;
    bool isNegative = false;
    if (x < 0)
    {
        isNegative = true;
    }
    while (x != 0)
    {
        vec.push_back(x % 10);
        x /= 10;
    }
    if (vec[0] == 0)
        vec.erase(vec.begin());
    long ans = 0;
    int n = vec.size() - 1;
    for (int i = 0; i != vec.size(); ++i)
    {
        ans += vec[i] * pow(10, n);
        n--;
        if (ans > INT_MAX)
            return 0;
        if (ans < INT_MIN)
            return 0;
    }
    return ans;
}