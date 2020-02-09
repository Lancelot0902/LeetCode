### 4. 4sum

和3sum一样的算法

```
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i != nums.size(); ++i)
    {
        for (int j = i + 1; j != nums.size(); ++j)
        {
            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == res.back()[2])
                        l += 1;
                    while (l < r && nums[r] == res.back()[3])
                        r -= 1;
                }
                if (sum < target)
                    l += 1;
                if (sum > target)
                    r -= 1;
            }
            while ((j < nums.size() - 1) && (nums[j] == nums[j + 1]))
                j += 1;
        }
        while ((i < nums.size() - 1) && (nums[i] == nums[i + 1]))
            i += 1;
    }
    return res;
}
```
