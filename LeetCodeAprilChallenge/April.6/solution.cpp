#include <iostream>
#include <vector>
#include <map>

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    for (string str : strs)
    {
        string t = str;
        sort(t.begin(), t.end());
        map[t].push_back(str);
    }
    vector<vector<string>> res;
    for (auto i : map)
    {
        res.push_back(i.second);
    }
    return res;
}
