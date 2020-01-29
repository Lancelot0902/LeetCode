#include <iostream>
#include <string>
#include <vector>

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
