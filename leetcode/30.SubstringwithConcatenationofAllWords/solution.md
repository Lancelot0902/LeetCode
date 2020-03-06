### 30. Substring with Concatenation of All Words

题目比较简单，比较容易想到的就是暴力法，再找一个vector存放查找的结果，如果找到对应的str，就从vector中删除，如果vector为空就说明找到了满足要求的位置

```
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
```

暴力法最后一个测试tle了，想了一下，应该是对tmp的操作耗时长了，如果words有一个string重复了许多次，那么tmp就要对这个string进行重复多次的添加和删除，所以这里需要改进

利用map存储一个string出现的次数

```
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
```
