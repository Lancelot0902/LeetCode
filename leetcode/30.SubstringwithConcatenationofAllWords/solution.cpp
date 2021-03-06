#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    if (s.empty() || words.empty())
        return {};
    std::vector<int> ans;
    int m = words.size();
    int n = words[0].size();
    std::vector<std::string> tmp;
    int i, j;
    for (i = 0; i + m * n <= s.size(); ++i)
    {
        tmp = words;
        for (j = i; j < i + m * n; j += m)
        {
            std::string str = s.substr(j, n);
            auto it = std::find(tmp.begin(), tmp.end(), str);
            if (it == tmp.end())
                break;
            tmp.erase(it);
        }
        if (j == i + m * n && tmp.empty())
            ans.push_back(i);
    }
    return ans;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    if (s.empty() || words.empty())
        return {};
    std::vector<int> ans;
    int m = words.size();
    int n = words[0].size();
    std::unordered_map<string, int> mp, tmp;
    std::vector<int> ans;
    for (auto it : words)
        mp[it] += 1;
    std::string str;
    int i, j;
    for (i = 0; i + m * n <= s.size(); ++i)
    {
        for (j = i; j < i + m * n; k += n)
        {
            str = s.substr(j, n);
            if (mp.find(str) == mp.end())
                break;
            ++tmp[str];
        }
        if (j == i + m * n && tmp == mp)
            ans.push_back(i);
        tmp.clear();
    }
    return ans;
}
