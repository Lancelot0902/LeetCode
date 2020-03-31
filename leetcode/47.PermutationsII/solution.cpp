#include <iostream>
#include <vector>

void dfs(std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> temp, std::vector<bool> &used)
{
    if (temp.size() == nums.size())
        ans.push_back(temp);
    else
    {
        for (int i = 0; i != nums.size(); ++i)
        {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            temp.push_back(nums[i]);
            used[i] = true;
            dfs(nums, ans, temp, used);
            used[i] = false;
            temp.pop_back();
        }
    }
}

std::vector<vector<int>> permuteUnique(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;
    std::vector<bool> used(nums.size());
    dfs(nums, ans, temp, used);
    return ans;
}
