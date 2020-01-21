#include <iostream>
#include <vector>
#include <map>

/* 暴力 */
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> ans;
    for (int i = 0; i != nums.size(); ++i)
    {
        for (int j = i + 1; j != nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

/* two-pass */
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> indices;
    std::vector<int> ans;
    for (int i = 0; i != nums.size(); ++i)
    {
        indices[nums[i]] = i;
    }
    for (int i = 0; i != nums.size(); ++i)
    {
        int temp = target - nums[i];
        if (indices.find(temp) != indices.end())
        {
            if (indices.at(temp) != i)
            {
                ans.push_back(i);
                ans.push_back(indices[temp]);
                break;
            }
        }
    }
    return ans;
}

/* one-pass */
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> indices;
    std::vector<int> ans;
    for (int i = 0; i != nums.size(); ++i)
    {
        int temp = target - nums[i];
        if (indices.find(temp) == indices.end())
        {
            indices[nums[i]] = i;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(indices.at(temp));
        }
    }
    return ans;
}
