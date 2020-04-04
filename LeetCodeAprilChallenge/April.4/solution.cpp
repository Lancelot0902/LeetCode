#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    std::vector<int> vec(nums.size(), 0);
    int j = 0;
    for (auto i : nums)
        if (i != 0)
            vec[j++] = i;
    nums = vec;
}

void moveZeroes(std::vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    int zero = 0;
    for (int i = 0; i != nums.size(); ++i)
    {
        if (nums[i] != 0)
            std::swap(nums[i], nums[zero++]);
    }
}
