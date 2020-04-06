### 49. Group Anagrams

将strs中的字符串排序，然后使用一个map来存储，将排序后一样的字符串添加到一个vector中

```
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
```
