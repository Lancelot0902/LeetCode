#include <iostream>
#include <vector>
#include <string>

int longestValidParentheses(std::string s)
{
    int ans = 0;
    std::vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                if (i >= 2)
                    dp[i] = dp[i - 2] + 2;
                else
                    dp[i] = 2;
            }
            else
            {
                if ((i - dp[i - 1] > 0) && (s[i - dp[i - 1] - 1] == '('))
                {
                    if (i - dp[i - 1] >= 2)
                        dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                    else
                        dp[i] = dp[i - 1] + 2;
                }
            }
        }
        ans = ans < dp[i] ? dp[i] : ans;
    }
    return ans;
}

int longestValidParentheses(std::string s)
{
    int ans = 0;
    std::vector<int> stack;
    stack.push_back(-1);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            stack.push_back(i);
        else
        {
            stack.pop_back();
            if (stack.empty())
                stack.push_back(i);
            else
                ans = max(ans, i - stack.back());
        }
    }
    return ans;
}

int longestValidParentheses(std::string s)
{
    int ans = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            left += 1;
        if (s[i] == ')')
            right += 1;
        if (left == right)
            ans = max(ans, right * 2);
        else if (right >= left)
            left = right = 0;
    }

    left = right = 0;

    for (int i = s.size() - 1; i >= 0; ++i)
    {
        if (s[i] == '(')
            left += 1;
        if (s[i] == ')')
            right += 1;
        if (left == right)
            ans = max(ans, right * 2);
        else if (left >= right)
            left = right = 0;
    }

    return ans;
}
