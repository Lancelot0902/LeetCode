#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2)
{
    if (num1.empty() || num2.empty())
        return "";
    if (num1 == "0" || num2 == "0")
        return "0";
    int n = num1.size();
    int m = num2.size();
    std::string ret;
    std::vector<int> nums(m + n);
    for (int i = n - 1; i >= 0; --i)
    {
        int p = num1[i] - '0';
        for (int j = m - 1; j >= 0; --j)
        {
            int q = num2[j] - '0';
            int num = nums[i + j + 1] + p * q;
            nums[i + j + 1] = num % 10;
            nums[i + j] += num / 10;
        }
    }
    for (int i = 0; i != nums.size(); ++i)
    {
        if (i == 0 && nums[i] == 0)
            continue;
        else
            ret += nums[i] + '0';
    }
    return ret;
}