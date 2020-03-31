### 47. Permutations II

这个题和46题思路一样，只是问题在于如何去除重复的部分，可以考虑一下什么情况下会有重复的部分 [1,1,2]，这种情况下1作为头部会出现重复，代码如何写呢，```nums[i] == nums[i-1]``` ？这样写当然不行，因为只考虑了广度的情况，没有考虑深度的情况，这时我们就需要使用一个used数组来表示某个数的使用情况，如果```used[i-1] = true``` 使用过了表明当前的程序是在向下进行，也就是增加深度的时候，这时不算重复，如果 ```used[i-1] = false``` 表明当前的程序是在横向进行，这时就需要考虑重复的问题了

```
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
```
