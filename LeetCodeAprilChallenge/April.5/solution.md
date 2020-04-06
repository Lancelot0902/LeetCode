# 122. Best Time to Buy and Sell Stock II

贪心法，贪心策略是只要第二天的股票比第一天的高那么就卖出，然后再买进第二天的股票

```
int maxProfit(std::vector<int> &prices)
{
    int ans = 0;
    for (int i = 1; i != prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
            ans += prices[i] - prices[i - 1];
    }
    return ans;
}
```
