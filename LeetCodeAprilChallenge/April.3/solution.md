### 53. Maximum Subarray

很明显是一道动态规划题，首先考虑 ```dp[i]``` 表示什么意思，因为我们的程序是向右进行，在前进过程中要计算和，并考虑如何处理，所以 ```dp[i]```表示以 ```nums[i]``` 为结尾的和最大的子数组，然后考虑我们的状态转移方程，当进行到 ```nums[i]``` 时，若 ```dp[i-1] < 0``` 时我们直接不要前面的 ```dp[i-1]```，因为这只会拉我们的后腿，所以这时 ```dp[i] = nums[i]```；否则 ```dp[i] = dp[i-1] + nums[i]```

```
int maxSubArray(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;
    std::vector<int> dp(n);
    dp[0] = nums[0];
    int max = 0;
    for (int i = 1; i != nums.size(); ++i)
    {
        if (dp[i - 1] < 0)
            dp[i] = nums[i];
        else
            dp[i] = nums[i] + dp[i - 1];
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}
```
