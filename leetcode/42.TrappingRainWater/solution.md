### 42. Trapping Rain Water

解法1：暴力法

计算每个点能乘装的容量，如何计算呢？从这个点分别向左向右找最大值，然后从两个值中找出较小的那个减去当前点的值就是当前点所能装的水

```
int trap(std::vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int n = height.size();
    for (int i = 1; i != n; ++i)
    {
        int max_left = 0;
        int max_right = 0;
        for (int j = i; j >= 0; --j)
            max_left = std::max(max_left, height[j]);
        for (int j = i; j != n; ++j)
            max_right = std::max(max_right, height[j]);
        ans += std::min(max_right, max_left) - height[i];
    }
    return ans;
}
```

解法2：动态规划

在暴力法中我们对每个点都要求左右两边的最大值，这做了许多重复工作，我们可以用两个数组来保持某个点的左右最大值

```
int trap(std::vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int n = height.size();
    std::vector<int> max_left(n);
    std::vector<int> max_right(n);

    max_left[0] = height[0];
    for (int i = 1; i != n; ++i)
        max_left[i] = std::max(max_left[i - 1], height[i]);

    max_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i)
        max_right[i] = std::max(max_right[i + 1], height[i]);

    for (int i = 1; i != n; ++i)
        ans += std::min(max_left[i], max_right[i]) - height[i];
    return ans;
}
```

解法3：两个指针

我们只做一次遍历，从头和尾同时做，如果 ```left > right``` ，那么所乘的水就取决于left，如果 ```left > max_left```，那么更新max_left，否则，计算结果加到ans上，右边同理

```
int trap(std::vector<int> &height)
{
    if(height.empty())
        return 0;
    int left = 0;
    int right = height.size() - 1;
    int max_left = 0;
    int max_right = 0;
    int ans = 0;

    while (left < right)
    {
        if(height[left] < height[right])
        {
            if (height[left] > max_left)
                max_left = height[left];
            else
                ans += max_left - height[left];
            left += 1;
        }
        else
        {
            if(height[right] > max_right)
                max_right = height[right];
            else
                ans += max_right - height[right];
            right -= 1;
        }
    }
    return ans;
}
```
