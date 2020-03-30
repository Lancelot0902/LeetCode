#include <vector>
#include <iostream>

int jump(std::vector<int> &nums)
{
    int ans = 0;
    int start = 0;
    int end = 1;
    while (end < nums.size())
    {
        int pos = 0;
        for (int i = start; i < end; ++i)
        {
            pos = std::max(pos, nums[i] + i);
        }
        start = end;
        end = pos + 1;
        ans += 1;
    }
    return ans;
}

int jump(std::vector<int> &nums)
{
    int pos = 0;
    int ans = 0;
    int end = 0;
    for (int i = 0; i != nums.size() - 1; ++i)
    {
        pos = std::max(pos, nums[i] + i);
        if (i == end)
        {
            ans += 1;
            end = pos;
        }
    }
    return ans;
}
