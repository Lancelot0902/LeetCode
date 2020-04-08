### Counting Elements

解法1：暴力

```
int countElements(std::vector<int> &arr)
{
    int ans = 0;
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        for (auto j = arr.begin(); j != arr.end(); ++j)
        {
            if (*j == *i + 1)
            {
                ans += 1;
                break;
            }
        }
    }
    return ans;
}
```

解法2：使用map

```
int countElements(std::vector<int> &arr)
{
    std::map<int, int> m;
    int ans = 0;
    for (int i = 0; i != arr.size(); ++i)
    {
        m[arr[i]] += 1;
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (m.find(it->first + 1) != m.end())
            ans += it->second;
    }
    return ans;
}
```
