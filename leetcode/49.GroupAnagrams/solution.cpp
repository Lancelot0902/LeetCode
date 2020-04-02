#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::vector<std::vector<std::string>> ans;
    std::map<std::string, std::vector<string>> m;
    for (auto str : strs)
    {
        std::string s = str;
        std::sort(s.begin(), s.end());
        m[s].push_back(str);
    }
    for (auto it : m)
        ans.push_back(it.second);
    return ans;
}
