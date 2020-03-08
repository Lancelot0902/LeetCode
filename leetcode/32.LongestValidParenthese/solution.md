### 32. Longest Valid Parentheses

刚开始尝试用栈来解决，但是有两个问题没有解决

* "((()))" 这样的情况不知如何判断
* 不知道如何解决连续和非连续的关系，也就是 "()(())" 这个是连续的，"()(()" 这个是非连续的

另外尝试动态规划解决，也遇到了相同的问题，然后再看题解，每种方法都给我耳目一新的感觉

动态规划

```
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
```

* s[i] == '(' dp[i] = 0
* s[i] == ')' 
    * s[i-1] == '(' 时 dp[i] = dp[i-2] + 2
    * s[i-1] == ')' 时遇到了'(())'这种情况，首先要检查前面对应位置的括号是否匹配，对应位置如何找呢？可以利用dp[i-1]的记录，dp[i-1]记录着前面的子串位置,i-dp[i-1]-1就是对应括号的位置，如果括号不匹配就跳过，匹配的话dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2]，最后一项是匹配括号前面的结果

利用栈

```
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
```

* s[i] == '('，将i入栈
* s[i] == ')'
    * 若栈为空，则i入栈
    * 若栈不为空，则 i-peek 得当前有效子串的长度

利用元素位置相减解决了 " (()) " 这样的情况

双指针

```
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
```

从左到右
* s[i] == '(' 时，left ++
* s[i] == ')' 时，right ++

当left == right 时，遇到有效括号，right*2即为长度，当right > left 时，重置 left 和 right

从右到左再重复一遍上述过程

对于我来说还是"(())"这样的情况不知如何处理，做题不够灵活
