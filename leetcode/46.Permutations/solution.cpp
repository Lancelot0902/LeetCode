#include <iostream>
#include <vector>

void dfs(std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> temp, int begin)
{
    if (begin == nums.size())
    {
        ans.push_back(temp);
    }
    else
    {
        for (int i = begin; i != nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            std::swap(nums[i], nums[begin]);
            dfs(nums, ans, temp, begin + 1);
            std::swap(nums[i], nums[begin]);
            temp.pop_back();
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    dfs(nums, ans, temp, 0);
    return ans;
}
