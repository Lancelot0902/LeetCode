### 15. 3 Sum

解法：Two Pointer

外层循环每次固定1个数，然后用来个指针不断逼近固定数的相反数

```
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    if(nums.size() < 3)
        return {};
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i != nums.size() - 1;++i)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == res.back().at(1))
                    l += 1;
                while (l < r && nums[r] == res.back().at(2))
                    r += 1;
            }
            if(sum > 0)
                r -= 1;
            if (sum < 0)
                l += 1;
        }
        while(nums[i] == nums[i+1])
            i += 1;
    }
    return res;
}
```

时间复杂度：n<sup>2
