#include <iostream>
#include <vector>
#include <map>
#include <string>

void dfs(std::map<char, std::string> &m, std::vector<std::string> &res, std::string &str, int pos)
{
    if (pos == str.size())
        return;
    std::string s = m[str[pos]];
    int n = res.size();
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != s.size(); ++j)
        {
            std::string temp = res[i];
            temp += s[j];
            res.push_back(temp);
        }
    }
    res.erase(res.begin(), res.begin() + n);
    dfs(m, res, str, pos + 1);
}

std::vector<std::string> letterCombinations(std::string digits)
{
    std::map<char, std::string> m;
    std::vector<std::string> res;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    std::string temp;
    res.push_back(temp);
    dfs(m, res, digits, 0);
    return res;
}
