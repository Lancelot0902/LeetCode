#include <iostream>
#include <algorithm>
#include <vector>

void nextPermutation(std::vector<int> &nums)
{
    int i = 0;
    for (i = nums.size() - 1; i >= 1; --i)
    {
        if (nums[i] <= nums[i - 1])
            continue;
        else
        {
            int j = i;
            while (nums[j] > nums[i - 1] && j <= nums.size() - 1)
                j += 1;
            j -= 1;
            std::swap(nums[i - 1], nums[j]);
            std::sort(nums.begin() + i, nums.end());
            break;
        }
    }
    if (i == 0)
        std::sort(nums.begin(), nums.end());
    return;
}
