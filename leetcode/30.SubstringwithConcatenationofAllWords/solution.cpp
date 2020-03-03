#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> findSubstring(std::string s,std::vector<std::string>& words)
{
    if(s.empty() || words.empty())
        return {};
    std::vector<int> ans;
    int m = words.size();
    int n = words[0].size();
}
