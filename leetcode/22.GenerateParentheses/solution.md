### 22. Generate Parentheses

解法1：暴力法

列举所有的组合，并检测是否有效

-------------------------------

解法2：回溯法

每添加一个左括号就添加一个右括号，这样就保证了解的有效性

```
void dfs(std::vector<std::string> &res, std::string temp, int left, int right, int n)
{
    if (temp.size() == 2 * n)
    {
        res.push_back(temp);
        return;
    }
    if (left < n)
        dfs(res, temp + '(', left + 1, right n);
    if (right < left)
        dfs(res, temp + ')', left, right + 1, n);
}

std::vector<std::string> generateParenthesis(int n)
{
    if (n == 0)
        return std::vector<std::string>{""};
    else
    {
        std::vector<std::string> res;
        string tmp;
        backTrack(res, tmp, 0, 0, n);
        return res;
    }
}
```
