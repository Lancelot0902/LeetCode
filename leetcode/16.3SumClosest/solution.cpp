#include <iostream>
#include <algorithm>
#include <vector>

int threeSumClosest(std::vector<int> &nums, int target)
{
    std::sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2] - target;
    int dif = abs(nums[0] + nums[1] + nums[2] - target);
    for (int i = 0; i != nums.size(); ++i)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < dif)
            {
                dif = abs(sum - target);
                ret = sum;
            }
            if (sum - target > 0)
                r -= 1;
            if (sum - target < 0)
                l += 1;
        }
    }
    return ret;
}
