#include <iostream>
#include <vector>

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
