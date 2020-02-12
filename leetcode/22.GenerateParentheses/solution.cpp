#include <iostream>
#include <vector>
#include <string>

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
