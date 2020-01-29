### 10. Regular Expression Matching

解法1：动态规划

转移方程 :

* 最简单的s[ i ] == p[ j ]时或p[ j ] == ' . ' 时，dp[i][j] = dp[i-1][j-1]

* 然后就是p[ j ] == ' * ' 时，有两种情况

    * p[j - 1] == s[i - 1] || p[j - 1] == '.' 时，要考虑p[j - 1]是删去还是重复1次或多次，dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]

    * 对于不能使前面相等的只能删掉，dp[i][j] = dp[i][j - 2]

```
bool isMatch(std::string s, std::string p)
{
    std::vector<std::vector<bool>> dp;
    dp.resize(s.size() + 1);
    for (int i = 0; i != s.size() + 1; ++i)
        dp[i].resize(p.size() + 1, false);
    dp[0][0] = true;
    for (int i = 2; i <= p.size(); ++i)
    {
        if (p[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    }
    for (int i = 1; i != s.size() + 1; ++i)
    {
        for (int j = 1; j != p.size() + 1; ++j)
        {
            if (s[i - 1] == p[i - 1] || p[i - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[i - 1] == '*')
            {
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 2];
            }
        }
    }
    return dp[s.size()][p.size()];
}
```

时间复杂度：n<sup>2

空间复杂度：n<sup>2