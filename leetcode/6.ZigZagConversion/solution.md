### 6.ZigZag conversion

解法1：按行访问

```
string convert(string s, int numRows) 
{
    if(s.size()<=numRows||numRows==1)
    {
        return s;
    }
    else
    {
        string ret;
        int T = numRows + numRows - 2;
        for (int i = 0; i != numRows; i++)
        {
            for (int j = 0; j != s.size(); j++)
            {
                if (j%T == i || T - j % T == i)
                {
                    ret.push_back(s[j]);
                }
            }
        }
        return ret;
    }
}
```

时间复杂度：N

空间复杂度：N

-------------------------------

解法2：按方向访问

从两个方向（向下、向上）遍历即可，在边界转换一下方向

```
std::string convert(std::string s, int numRows)
{
    std::vector<std::string> vec;
    std::string ans;
    vec.resize(numRows);
    int it = 0;
    bool direction = true;
    for (int i = 0; i != s.size(); ++i)
    {
        if (direction)
        {
            vec[it++] += s[i];
            if (it == numRows)
            {
                direction = false;
                it -= 2;
                continue;
            }
        }
        if (!direction)
        {
            vec[it--] += s[i];
            if (it == -1)
            {
                direction = true;
                it += 2;
                continue;
            }
        }
    }
    for (auto i : vec)
        ans += i;
    return ans;
}
```

时间复杂度：N

空间复杂度：N