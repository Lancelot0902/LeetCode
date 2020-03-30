### 44. Wildcard Matching

很有意思的动态规划，首先要明白dp数组的含义，我们声明一个```(m+1)*(n+1)```的二维数组，dp[i][j]表示，字符串s从0到i-1（[0,i-1]）和字符串p从0到j-1（[0,j-1]）的匹配结果，然后找出动态方程

* 如果s[i-1] == p[j-1] || p[j-1] == '?'，dp[i][j] = dp[i-1][j-1]
* 如果p[j-1] == '*'，分两种情况，一个是 * 代表null，另一个是代表任意字符串，这两种情况有一种为真即可
    * 代表null时，dp[i][j] = dp[i][j-1]
    * 代表任意子串时，dp[i][j] = dp[i-1][j]

```
bool isMatch(std::string s, std::string p)
{
    int m = s.size();
    int n = p.size();
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}
```

本题需要先初始化dp，因为在后面的循环中涉及到了访问i-1，j-1；
