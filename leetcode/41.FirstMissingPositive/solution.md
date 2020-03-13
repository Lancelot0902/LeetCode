### 41. First Missing Positive

这个题将数组当做哈希表的思想很有趣，如果 ```nums[i] = 5 ```，那么将 ```nums[i]``` 和 ```nums[4]``` 交换，当然要满足交换条件

```
int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i != n; ++i)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            std::swap(nums[nums[i] - 1], nums[i]);
    }
    for (int i = 0; i != n; ++i)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

```
