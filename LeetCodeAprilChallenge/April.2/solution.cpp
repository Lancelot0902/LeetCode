#include <iostream>
#include <set>

bool isHappy(int n)
{
    std::set<int> nums;
    while (1)
    {
        int temp = 0;
        while (n)
        {
            temp += std::pow(n % 10, 2);
            n /= 10;
        }
        n = temp;
        if (n == 1)
            return true;
        if (nums.find(n) == nums.end())
            nums.insert(n);
        else
            return false;
    }
}
