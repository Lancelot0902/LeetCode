### 45. Jump Game II

很经典的贪心问题，本题的贪心策略：在能跳的范围内选取能跳最远的位置跳

举个例子 ```[2,3,1,1,4]```,开始位置是 2，我们能跳的边界到第一个 1，在这个范围内，跳到 3 能够使我们的边界最大，所以跳到 3，然后从 3 开始，3 的边界直接到数组尾部，直接结束

```
int jump(std::vector<int>& nums)
{
    int ans = 0;
    int start = 0;
    int end = 1;
    while (end < nums.size())
    {
        int pos = 0;
        for (int i = start; i < end; ++i)
        {
            pos = std::max(pos, nums[i] + i);
        }
        start = end;
        end = pos + 1;
        ans += 1;
    }
    return ans;
}
```
