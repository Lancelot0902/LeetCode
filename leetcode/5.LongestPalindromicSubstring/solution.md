### 5. Longest Palindromic Substring

解法1：动态规划

```
std::string longestPalindrome(std::string s)
{
    std::vector<std::vector<bool>> dp;
    int max = 1;
    int left = 0;
    dp.resize(s.size());
    for (int i = 0; i != dp.size();++i)
        dp[i].resize(s.size());
    for (int i = 0; i != dp.size();++i)
        dp[i][i] = true;
    for (int i = 0; i != dp.size();++i)
    {
        for (int j = 0; j != i;++j)
        {
            if(s[i] == s[j] && (i-j<3 || dp[j+1][i-1]))
            {
                dp[j][i] = true;
                max = (i - j + 1) > max ? i - j + 1 : max;
                left = j;
            }
        }
    }
    return s.substr(left, max);
}
```

时间复杂度：N<sup>2

空间复杂度：N<sup>2

----------------------------

解法2：从中心拓展

一个回文串必定是对称的，所以可以从中间向两边扩展，一个串有2n-1个中心，一个字符为中心有n个，两个字符为中心有n-1个

```
std::string longestPalindrome(std::string& s)
{
        int start = 0;
        int end = 0;
        int max = 0;
        for (int i = 0; i != s.size();++i)
        {
            int len1 = expendCenter(i, i, s);
            int len2 = expendCenter(i, i + 1, s);
            int len = len1 > len2 ? len1 : len2;
            max = len > max ? len : max;
            if(max > end-start+1)
            {
                start = i - (max - 1) / 2;
                end = i + max / 2;
            }
        }
        return s.substr(start, max);
}
```