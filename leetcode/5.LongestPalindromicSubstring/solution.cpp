#include <iostream>
#include <vector>
#include <string>

std::string longestPalindrome(std::string s)
{
    std::vector<std::vector<bool>> dp;
    int max = 1;
    int left = 0;
    dp.resize(s.size());
    for (int i = 0; i != dp.size(); ++i)
        dp[i].resize(s.size());
    for (int i = 0; i != dp.size(); ++i)
        dp[i][i] = true;
    for (int i = 0; i != dp.size(); ++i)
    {
        for (int j = 0; j != i; ++j)
        {
            if (s[i] == s[j] && (i - j < 3 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;
                max = (i - j + 1) > max ? i - j + 1 : max;
                left = j;
            }
        }
    }
    return s.substr(left, max);
}

int expendCenter(int l, int r, std::string s)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

std::string longestPalindrome(std::string &s)
{
    int start = 0;
    int end = 0;
    int max = 0;
    for (int i = 0; i != s.size(); ++i)
    {
        int len1 = expendCenter(i, i, s);
        int len2 = expendCenter(i, i + 1, s);
        int len = len1 > len2 ? len1 : len2;
        max = len > max ? len : max;
        if (max > end - start + 1)
        {
            start = i - (max - 1) / 2;
            end = i + max / 2;
        }
    }
    return s.substr(start, max);
}
